/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson@gmail.com>
 *
 * The zlog Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The zlog Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the zlog Library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "zc_defs.h"
#include "buf.h"

int main(int argc, char** argv)
{
	zlog_buf_t *a_buf;
	char *aa;

	a_buf = zlog_buf_new(10, 20, "ABC");
	if (!a_buf) {
		zc_error("zlog_buf_new fail");
		return -1;
	}

	aa = "123456789";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	fwrite(a_buf->start, zlog_buf_len(a_buf), 1, stdout);
	zc_error("------------");

	aa = "0";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	aa = "12345";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	aa = "6789";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");
	
	aa = "0";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");
	
	aa = "22345";
	zlog_buf_append(a_buf, aa, strlen(aa));
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");


	aa = "abc";
	int i,j;
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 5; j++) {
			zlog_buf_restart(a_buf);
			zc_error("left[1],max[%d],min[%d]", i, j);
			zlog_buf_adjust_append(a_buf, aa, strlen(aa), 1, i, j);
			zc_error("a_buf->start[%s]", a_buf->start);

			zc_error("-----");

			zlog_buf_restart(a_buf);
			zc_error("left[0],max[%d],min[%d]", i, j);
			zlog_buf_adjust_append(a_buf, aa, strlen(aa), 0, i, j);
			zc_error("a_buf->start[%s]", a_buf->start);
			zc_error("------------");
		}
	}

	aa = "1234567890";
	zc_error("left[0],max[%d],min[%d]", 15, 5);
	zlog_buf_adjust_append(a_buf, aa, strlen(aa), 0, 15, 5);
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	aa = "1234567890";
	zlog_buf_restart(a_buf);
	zc_error("left[0],max[%d],min[%d]", 25, 5);
	zlog_buf_adjust_append(a_buf, aa, strlen(aa), 1, 25, 5);
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	zlog_buf_restart(a_buf);
	zc_error("left[0],max[%d],min[%d]", 19, 5);
	zlog_buf_adjust_append(a_buf, aa, strlen(aa), 0, 19, 5);
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	zlog_buf_restart(a_buf);
	zc_error("left[0],max[%d],min[%d]", 20, 5);
	zlog_buf_adjust_append(a_buf, aa, strlen(aa), 0, 20, 5);
	zc_error("a_buf->start[%s]", a_buf->start);
	zc_error("------------");

	zlog_buf_del(a_buf);
	
	return 0;
}

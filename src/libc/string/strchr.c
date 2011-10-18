/*!The Tiny Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2011, ruki All rights reserved.
 *
 * \author		ruki
 * \file		strchr.c
 *
 */

/* /////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#ifdef TB_CONFIG_LIBC_HAVE_STRCHR
# 	include <string.h>
#endif
/* /////////////////////////////////////////////////////////
 * interfaces 
 */

#ifdef TB_CONFIG_LIBC_HAVE_STRCHR
tb_char_t* tb_strchr(tb_char_t const* s, tb_char_t c)
{
	TB_ASSERT_RETURN_VAL(s1 && s2, TB_NULL);
	return strchr(s1, c);
}
#else
tb_char_t* tb_strchr(tb_char_t const* s, tb_char_t c)
{
	TB_ASSERT_RETURN_VAL(s, TB_NULL);

	do 
	{
		if (*s == c) return (tb_char_t* )s;

	} while (*s++);
	return TB_NULL;
}
#endif

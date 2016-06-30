/*!The Treasure Box Library
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
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        print.c
 * @ingroup     platform
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include <stdio.h>
#include <windows.h>

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */

/* 
 *@note
 *
 * fputs(string, stdout) exists compatibility issue when vs2008 => vs2015 
 *
 * error: ___iob_func undefined in vs2015 
 */
tb_void_t tb_print(tb_char_t const* string)
{
    // check
    tb_check_return(string);

    // get stdout
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    tb_assert_and_check_return(handle != INVALID_HANDLE_VALUE);

    // the data and size
    tb_byte_t const*    data = (tb_byte_t const*)string;
    tb_size_t           size = tb_strlen(string) + 1;

    // write string to stdout
    tb_size_t writ = 0;
    while (writ < size)
    {
        // write to the stdout
        DWORD real = 0;
        if (!WriteFile(handle, data + writ, (DWORD)(size - writ), &real, tb_null)) break;

        // update writted size
        writ += (tb_size_t)real;
    }
}
tb_void_t tb_printl(tb_char_t const* string)
{
    // print string 
    tb_print(string);

    // print newline 
    tb_print(__tb_newline__);
}
tb_void_t tb_print_sync()
{
}

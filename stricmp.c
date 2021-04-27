/*
 * stricmp.c
 *
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 *
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */

#include "strings.h"

int
tb_stricmp(char *str1, char *str2)
{
    char c;
    int res;
    while (*str1 && *str2 &&
           !(res = (((unsigned)(c = *str1 & '_') - 'A') < 26 ? c : *str1) -
                   (((unsigned)(c = *str2 & '_') - 'A') < 26 ? c : *str2)))
    {
        str1++;
        str2++;
    }
    if (!res) res = *str1 - *str2;
    return res < 0 ? -1 : !!res;
}

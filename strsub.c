/*
 * strsplit.c
 *
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 *
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */

#include "strings.h"

char *
tb_strsub(char *str, int idx, int len)
{
    char *newstr = NULL;
    int slen = tb_strlen(str);

    if (((unsigned)idx) < slen && len < ((unsigned int)slen - 1))
    {
        newstr = tb_strndup(str + idx, len);
    }
    return newstr;
}

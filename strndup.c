/*
 * tb_strndup.c
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
tb_strndup(char *srcstr, int len)
{
    char *newstr;
    if ((newstr = (char *)malloc(len + 1)))
    {
        tb_memcpy(newstr, srcstr, len);
        newstr[len] = 0;
    }
    return newstr;
}

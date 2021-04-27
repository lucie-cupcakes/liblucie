/*
 * strreplace.c
 *
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 *
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */

#include "strings.h"

void
tb_strreplace(char **str, char *findstr, char *replace)
{
    char *newstr, *fs;
    int idx = 0, slen = tb_strlen(*str), flen = tb_strlen(findstr),
        rlen = tb_strlen(replace);

    newstr = tb_strdup(*str);
    while ((fs = tb_strfind(newstr + idx, findstr)))
    {
        idx = fs - newstr;
        if (!(fs = (char *)malloc(slen + rlen - flen + 1)))
        {
            free(newstr);
            newstr = NULL;
            break;
        }
        tb_memcpy(fs, newstr, idx);
        tb_memcpy(fs + idx, replace, rlen);
        tb_memcpy(fs + idx + rlen, newstr + idx + flen, slen - idx + flen + 1);
        free(newstr);
        newstr = fs;
    }
    if (newstr) *str = newstr;
}

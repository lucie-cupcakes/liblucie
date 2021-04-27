/*
 * strfind.c
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
tb_strfind(char *str, char *findstr)
{
    int spos = 0, fpos = 0, opos;

    while (str[spos])
    {
        while (str[spos] && str[spos] != *findstr) ++spos;
        opos = spos;
        while (str[spos] && findstr[fpos] && str[spos] == findstr[fpos])
        {
            ++spos;
            ++fpos;
        }
        if (!findstr[fpos] &&
            (!str[spos] || str[spos] == ' ' || str[spos] == '\t' ||
             str[spos] == '\n' || str[spos] == '\r'))
            break;
        fpos = 0;
        spos = ++opos;
    }

    return fpos ? str + opos : NULL;
}

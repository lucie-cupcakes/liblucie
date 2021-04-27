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

void tb_strsplit(char **str,char **split,int idx)
{
    char *newstr;

    if(*split) free(*split);
    newstr=tb_strndup(*str,idx);
    *split=tb_strdup(*str+idx);
    free(*str);
    *str=newstr;
}

/*
 * strrtrim.c
 * 
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 * 
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */


#include "strings.h"

char *tb_strrtrim(char *str)
{
    int len=tb_strlen(str);
    while(str[len-1]==' ' || str[len-1]=='\t') --len;
    return tb_strndup(str,len);
}

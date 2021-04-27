/*
 * tb_strltrim.c
 * 
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 * 
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */


#include "strings.h"

char *tb_strltrim(char *str)
{
    char *workstr=str;
    while(*workstr==' '||*workstr=='\t') ++workstr;

    return tb_strdup(workstr);
}

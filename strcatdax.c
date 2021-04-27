/*
 * strcatdax.c
 * 
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 * 
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */


#include "strings.h"

char *tb_strcatdax(char *str,char delim,int num,char **strarr)
{
    int dl, sl, tl,idx;

    sl=tb_strlen(str);
    for(idx=0;idx<num;idx++) {
      tl=dl=tb_strlen(strarr[idx]);
      str[sl++]=delim;
      str=realloc(str,sl+dl);
      while(dl-->0) str[sl+dl]=strarr[idx][dl];
      sl+=tl;
    }
    str[sl] = 0;
    return str;
}

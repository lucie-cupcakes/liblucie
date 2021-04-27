/*
 * strinsert.c
 * 
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 * 
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */


#include "strings.h"

char *tb_strinsert(char *str,char *insert, int idx)
{
    char *newstr;
    int slen=tb_strlen(str),ilen=tb_strlen(insert);

    if(((unsigned int)idx)>slen)
        return NULL;
    if(ilen==0) return str;
    newstr=malloc(slen+ilen+1);
    tb_memcpy(newstr,str,idx);
    tb_memcpy(newstr+idx,insert,ilen);
    tb_memcpy(newstr+idx+ilen,str+idx,slen-idx+1);
    return newstr;
}

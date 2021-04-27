// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#ifndef L_STRING_H_INCLUDED
#define L_STRING_H_INCLUDED
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#ifndef _BUILDLIB
#define EXTERN extern
#else
#define EXTERN
#endif

typedef int32_t l_strlen_t

typedef struct
{
    l_strlen_t length;
    char *value;
} l_string;

EXTERN int
tb_strlen(char *c_str);
EXTERN void *
tb_memcpy(void *dst, void *src, size_t size);
EXTERN void *
tb_memset(void *dst, int chr, size_t size);
EXTERN int
tb_memcmp(void *str1, void *str2, size_t size);

EXTERN char *
tb_strndup(char *srcstr, int len);

EXTERN char *
tb_strltrim(l_string *str);
EXTERN char *
tb_strrtrim(l_string *str);
EXTERN char *
tb_strlrtrim(l_string *str);
EXTERN char *
tb_strsub(l_string *str, int idx, int len);
EXTERN char *
tb_strinsert(l_string *str, char *insert, int idx);
EXTERN char *
tb_strfind(l_string *str, char *findstr);
EXTERN void
tb_strsplit(char **str, char **splt, int idx);
EXTERN void
tb_strreplace(char **str, char *findstr, char *replace);
EXTERN int
tb_strcmp(l_string *str1, l_string *str2);
EXTERN int
tb_stricmp(l_string *str1, l_string *str2);
EXTERN char *
tb_strcatx(l_string *str, int num, ...);
EXTERN char *
tb_strcatdx(l_string *str, char delim, int num, ...);
EXTERN char *
tb_strcatax(l_string *str, int num, char **strarr);
EXTERN char *
tb_strcatdax(l_string *str, char delim, int num, char **strarr);
#undef EXTERN
#endif // L_STRING_H_INCLUDED

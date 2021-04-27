// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#ifndef L_STRING_H_INCLUDED
#define L_STRING_H_INCLUDED
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
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

EXTERN l_string *
l_string_create(l_strlen_t length, char* value);

EXTERN int
l_strlen(char *c_str);
EXTERN void *
l_memcpy(void *dst, void *src, size_t size);
EXTERN void *
l_memset(void *dst, int chr, size_t size);
EXTERN int
l_memcmp(void *str1, void *str2, size_t size);

EXTERN l_string *
l_string_duplicate(l_string* str);

EXTERN char *
l_strltrim(l_string *str);
EXTERN char *
l_strrtrim(l_string *str);
EXTERN char *
l_strlrtrim(l_string *str);
EXTERN char *
l_strsub(l_string *str, int idx, int len);
EXTERN char *
l_strinsert(l_string *str, char *insert, int idx);
EXTERN char *
l_strfind(l_string *str, char *findstr);
EXTERN void
l_strsplit(char **str, char **splt, int idx);
EXTERN void
l_strreplace(char **str, char *findstr, char *replace);
EXTERN int
l_strcmp(l_string *str1, l_string *str2);
EXTERN int
l_stricmp(l_string *str1, l_string *str2);
EXTERN char *
l_strcatx(l_string *str, int num, ...);
EXTERN char *
l_strcatdx(l_string *str, char delim, int num, ...);
EXTERN char *
l_strcatax(l_string *str, int num, char **strarr);
EXTERN char *
l_strcatdax(l_string *str, char delim, int num, char **strarr);
#undef EXTERN
#endif // L_STRING_H_INCLUDED

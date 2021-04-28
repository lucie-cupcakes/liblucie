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

// Null Terminated & C Language Tools

EXTERN int
l_cstr_len(char *c_str);
EXTERN char *
l_cstr_dup(char *c_str);

EXTERN void *
l_memory_copy(void *dst, void *src, size_t size);
EXTERN void *
l_memory_set(void *dst, int chr, size_t size);
EXTERN int
l_memory_compare(void *str1, void *str2, size_t size);

// Lucie's String

typedef int32_t l_strlen_t

typedef struct
{
    l_strlen_t length;
    char *value;
} l_string;

EXTERN l_string *
l_string_create(l_strlen_t length, char* value);

EXTERN void
l_string_destroy(l_string* str);

EXTERN l_string *
l_string_duplicate(l_string* str);

EXTERN l_string *
l_string_trim_left(l_string *str);
EXTERN l_string *
l_string_trim_right(l_string *str);
EXTERN l_string *
l_string_trim_both(l_string *str);

EXTERN l_string *
l_string_take_slice(l_string *str, int idx, int len);

EXTERN l_string *
l_string_insert(l_string *str, char *insert, int idx);

EXTERN l_string *
l_string_find(l_string *str, char *findstr);

EXTERN void
l_string_split(char **str, char **splt, int idx);

EXTERN void
l_string_replace(char **str, char *findstr, char *replace);

EXTERN int
l_string_compare(l_string *str1, l_string *str2);
EXTERN int
l_string_compare_case(l_string *str1, l_string *str2);

// Not sure what to do with these yet:
EXTERN char *
l_strcatdx(l_string *str, char delim, int num, ...);
EXTERN char *
l_strcatax(l_string *str, int num, char **strarr);
EXTERN char *
l_strcatdax(l_string *str, char delim, int num, char **strarr);

#undef EXTERN
#endif // L_STRING_H_INCLUDED

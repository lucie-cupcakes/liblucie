// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#ifndef L_STRING_H_INCLUDED
#define L_STRING_H_INCLUDED

// C-STD Library
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef LUCIE_USE_STDLIB
#include <string.h>
#endif

#ifndef _BUILDLIB
#define EXTERN extern
#else
#define EXTERN
#endif

#ifndef l_assert
#if defined(LUCIE_NO_ASSERT) || defined(NDEBUG)
#define l_assert(x)
#else
#include <assert.h>
#define l_assert(x) assert(x)
#endif
#endif // l_assert

typedef struct {
    int32_t length;
    char *value;
} l_string;

// Null Terminated & C Language Tools
#if defined(LUCIE_USE_STDLIB) || defined(_BUILDLIB)
#define l_cstr_len(x) (int32_t) strlen(x)
#define l_cstr_dup(x) strdup(x)
#define l_memory_copy(dst, src, size) memcpy(dst, src, size)
#define l_memory_set(dst, chr, size) memset(dst, chr, size)
#define l_memory_compare(buff1, buff2, size) memcmp(buff1, buff2, size)
#else
EXTERN int32_t l_cstr_len(char *c_str);
EXTERN char *l_cstr_dup(char *c_str);
EXTERN void *l_memory_copy(void *dst, void *src, size_t size);
EXTERN void *l_memory_set(void *dst, int chr, size_t size);
EXTERN int l_memory_compare(void *buff1, void *buff2, size_t size);
#endif // LUCIE_USE_STDLIB

// Lucie's String
EXTERN l_string *l_string_create(int32_t length, const char *value);
EXTERN void l_string_destroy(l_string *str);
EXTERN l_string *l_string_duplicate(l_string *str);
EXTERN l_string *l_string_trim_left(l_string *str);
EXTERN l_string *l_string_trim_right(l_string *str);
EXTERN l_string *l_string_trim_both(l_string *str);
EXTERN l_string *l_string_take_slice(l_string *str, int32_t idx, int32_t len);
EXTERN l_string *l_string_insert(l_string *str, l_string *insert, int32_t idx);
EXTERN l_string *l_string_find(l_string *str, l_string *findstr);
// EXTERN void l_string_split(l_string *str, l_string **splt, int idx);
// EXTERN void l_string_replace(char **str, char *findstr, char *replace);
EXTERN int32_t l_string_compare(l_string *str1, l_string *str2);
EXTERN int32_t l_string_compare_case(l_string *str1, l_string *str2);

// Not sure what to do with these yet:
// EXTERN char *l_strcatdx(l_string *str, char delim, int num, ...);
// EXTERN char *l_strcatax(l_string *str, int num, char **strarr);
// EXTERN char *l_strcatdax(l_string *str, char delim, int num, char **strarr);

#undef EXTERN
#endif // L_STRING_H_INCLUDED

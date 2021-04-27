/*
 * strings.h
 *
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 *
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */

#ifndef _TBSTRINGS_H
#define _TBSTRINGS_H
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#ifndef _BUILDLIB
#define EXTERN extern
#else
#define EXTERN
#endif

/* strings.c */

#if defined(_USE_TOOLBOX) || defined(_BUILDLIB)
EXTERN int
tb_strlen(char *str);
EXTERN void *
tb_memcpy(void *dst, void *src, size_t size);
EXTERN void *
tb_memset(void *dst, int chr, size_t size);
EXTERN int
tb_memcmp(void *str1, void *str2, size_t size);
#else
#include <string.h>
#define tb_strlen(str) strlen(str)
#define tb_memcpy(dst, src, size) memcpy(dst, src, size)
#define tb_memset(dst, chr, size) memset(dst, chr, size)
#define tb_memcmp(str1, str2, size) memcmp(str1, str2, size)
#endif
EXTERN char *
tb_strndup(char *srcstr, int len);
EXTERN char *
tb_strdup(char *srcstr);
EXTERN char *
tb_strltrim(char *str);
EXTERN char *
tb_strrtrim(char *str);
EXTERN char *
tb_strlrtrim(char *str);
EXTERN char *
tb_strsub(char *str, int idx, int len);
EXTERN char *
tb_strinsert(char *str, char *insert, int idx);
EXTERN char *
tb_strfind(char *str, char *findstr);
EXTERN void
tb_strsplit(char **str, char **splt, int idx);
EXTERN void
tb_strreplace(char **str, char *findstr, char *replace);
EXTERN int
tb_strcmp(char *str1, char *str2);
EXTERN int
tb_stricmp(char *str1, char *str2);
EXTERN char *
tb_strcatx(char *str, int num, ...);
EXTERN char *
tb_strcatdx(char *str, char delim, int num, ...);
EXTERN char *
tb_strcatax(char *str, int num, char **strarr);
EXTERN char *
tb_strcatdax(char *str, char delim, int num, char **strarr);
#undef EXTERN
#endif

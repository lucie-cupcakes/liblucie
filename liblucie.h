// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#ifndef LIBLUCIE_INCLUDED
#define LIBLUCIE_INCLUDED

// C-STD Library
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

#ifdef LIBLUCIE_USE_STDLIB
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
#if defined(LIBLUCIE_USE_STDLIB) || defined(_BUILDLIB)
#define l_cstr_len(x) (int32_t) strlen(x)
#define l_cstr_dup(x) strdup(x)
#define l_memory_copy(dst, src, size) memcpy(dst, src, size)
#define l_memory_set(dst, chr, size) memset(dst, chr, size)
#define l_memory_compare(buff1, buff2, size) memcmp(buff1, buff2, size)
#else
EXTERN int32_t l_cstr_len(const char *c_str);
EXTERN char *l_cstr_dup(const char *c_str);
EXTERN void *l_memory_copy(void *dst, void *src, size_t size);
EXTERN void *l_memory_set(void *dst, int chr, size_t size);
EXTERN int l_memory_compare(void *buff1, void *buff2, size_t size);
#endif // LIBLUCIE_USE_STDLIB

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

/* @brief Duplicates a string.
 * This function calls malloc,
 * and the return pointer should be free'd after usage.
 * If the alloc fails, NULL be returned.
 * @param str The string to be duplicated.
 * @param str_len The length of the string.
 * @return Pointer to new allocated string.
 */
EXTERN char *l_strn_dup(const char *str, size_t str_len);
#define l_str_dup(str) l_strn_dup(str, l_cstr_len(str))

/* @brief Concatenates multiple strings into one buffer.
 * @param str Destination a string capable of holding all the desired
 * slices.
 * @param VA_LIST, NULL terminated list of slices (char array only).
 * @return Pointer to str.
 */
EXTERN char *l_str_catx(char *str, ...);

/* @brief Converts a base integer to a string.
 * @param seq Sequence, pass NULL to use the default.
 * @param base Base of numbers to use, if unsure, use 10.
 * @param num Number to be converted.
 * @param out_buff The result will be stored in this pointer, pass
 * NULL to have the function alloc this buffer for you.
 * @return Pointer the output string. If out_buff was passed, it is the same.
 */
EXTERN char *l_int_base_to_str(int num, int base, char *seq, char *out_buff);
#define l_int_to_str(num, out_buff) l_int_base_to_str(num, 10, NULL, out_buff)

/* @brief Converts a string to a base integer.
 * @param seq: Sequence, pass NULL to use the default.
 * @param base: Base of numbers to use, if unsure, use 10.
 * @param str: String containing the number to be converted.
 * @param str_len The length of the string.
 * @return Converted number.
 */
EXTERN int l_strn_to_int_base(const char *str, size_t str_len, int base, char *seq);
#define l_str_to_int_base(str, base, seq) l_strn_to_int_base(str, l_cstr_len(str), base, seq)
#define l_str_to_int(str) l_strn_to_int_base(str, l_cstr_len(str), 10, NULL)
#define l_strn_to_int(str, str_len) l_strn_to_int_base(str, str_len, 10, NULL)

/* @brief Gives the length of a string up to a delimiter.
 * Useful for diving by slices, without modifing the input buffer.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @param del: Delimiter character.
 * @param out_slice_len: this pointer is derefenced
 * and set with the length of the slice.
 * @return 1 if the delimiter was found, 0 if not.
 */
EXTERN int l_strn_slice(const char *str, size_t str_len, const char del, size_t *out_slice_len);
#define l_str_slice(str, del, out_slice_len) l_strn_slice(str, l_cstr_len(str), del, out_slice_len)

/* @brief Checks whenever a string is surronded by a character.
 * Useful for detecting quoted strings.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @param c: Character to check.
 * @return 1 if it is surronded, 0 if not.
 */
EXTERN int l_strn_is_surrc(const char *str, size_t str_len, const char c);
#define l_str_is_surrc(str, c) l_strn_is_surrc(str, l_cstr_len(str), c)

/* @brief Removes a character from a string being surronded by it.
 * Useful for removing quotes.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @param c: Character to check.
 * @return Pointer to the processed string.
 */
EXTERN char *l_strn_rm_surrc(char *str, size_t str_len, const char c);
#define l_str_rm_surrc(str, c) l_strn_rm_surrc(str, l_cstr_len(str), c)

/* @brief Removes leading whitespace from a string.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @return Pointer to the processed string.
 */
EXTERN char *l_strn_trim_left(char *str, size_t str_len);
#define l_str_trim_left(str) l_strn_trim_left(str, l_cstr_len(str))

/* @brief Removes leading whitespace from a string.
 * Does not modify the input.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @return Left offset from where there are no spaces.
 */
EXTERN size_t l_strn_trim_left_ro(const char *str, size_t str_len);
#define l_str_trim_left_ro(str) l_strn_trim_left_ro(str, l_cstr_len(str))

/* @brief Removes whitespace from the right side of a string.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @return Pointer to the processed string.
 */
EXTERN char *l_strn_trim_right(char *str, size_t str_len);
#define l_str_trim_right(str) l_strn_trim_right(str, l_cstr_len(str))

/* @brief Removes whitespace from the right side of a string.
 * Does not modify the input.
 * @param str: Input string.
 * @param str_len The length of the string.
 * @return The new string length
 */
EXTERN size_t l_strn_trim_right_ro(const char *str, size_t str_len);
#define l_str_trim_right_ro(str) l_strn_trim_right_ro(str, l_cstr_len(str))

/* @brief Checks if a string starts with another.
 * @param haystack: Input string.
 * @param needle: The string to find.
 * @param haystack_len: Length of the input string.
 * @param needle_len: Length of the string to find.
 * @return 1 if "haystack" starts with "needle", 0 if not.
 */
EXTERN int l_strn_starts_with(const char *haystack, const char *needle, size_t haystack_len,
                              size_t needle_len);
#define l_str_starts_with(haystack, needle)                                                                  \
    l_strn_starts_with(haystack, needle, l_cstr_len(haystack), l_cstr_len(needle))

/* @brief Counts how many time a character is inside a string
 * @param str: Input string.
 * @param str_len The length of the string.
 * @param c: The character to find.
 * @return The count of occurrences.
 */
EXTERN size_t l_strn_char_cnt(const char *str, size_t str_len, const char c);
#define l_str_char_cnt(str, c) l_strn_char_cnt(str, l_cstr_len(str_len), c)

#undef EXTERN
#endif // LIBLUCIE_INCLUDED

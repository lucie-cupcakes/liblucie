/* Go visit https://github.com/lucie-cupcakes/liblucie for the latest version */
/* MIT License, more info read FILE LICENSE or visit
 * https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE */

#ifndef LUCIE_LIB_INCLUDED
#define LUCIE_LIB_INCLUDED

#include <string.h>

/** @brief Duplicates a string.
 *  This function calls malloc,
 *  and the return pointer should be free'd after usage.
 *  If the alloc fails, NULL be returned.
 *  @param str The string to be duplicated.
 *  @param str_len The length of the string.
 *  @return Pointer to new allocated string.
 */
char *
l_strn_dup(const char *str, size_t str_len);
#define l_str_dup(str) l_strn_dup(str, strlen(str))

/** @brief Concatenates multiple strings into one buffer.
 *  @param str Destination a string capable of holding all the desired
 *	slices.
 *  @param VA_LIST, NULL terminated list of slices (char array only).
 *  @return Pointer to str.
 */
char *
l_str_catx(char *str, ...);

/** @brief Converts a base integer to a string.
 *  @param seq Sequence, pass NULL to use the default.
 *  @param base Base of numbers to use, if unsure, use 10.
 *  @param num Number to be converted.
 *  @param out_buff The result will be stored in this pointer, pass
 *  NULL to have the function alloc this buffer for you.
 *  @return Pointer the output string. If out_buff was passed, it is the same.
 */
char *
l_int_base_to_str(int num, int base, char *seq, char *out_buff);
#define l_int_to_str(num, out_buff) l_int_base_to_str(num, 10, NULL, out_buff)

/** @brief Converts a string to a base integer.
 *  @param seq: Sequence, pass NULL to use the default.
 *  @param base: Base of numbers to use, if unsure, use 10.
 *  @param str: String containing the number to be converted.
 *  @param str_len The length of the string.
 *  @return Converted number.
 */
int
l_strn_to_int_base(const char *str, size_t str_len, int base, char *seq);
#define l_str_to_int_base(str, base, seq)                                      \
    l_strn_to_int_base(str, strlen(str), base, seq)
#define l_str_to_int(str) l_strn_to_int_base(str, strlen(str), 10, NULL)
#define l_strn_to_int(str, str_len) l_strn_to_int_base(str, str_len, 10, NULL)

/** @brief Gives the length of a string up to a delimiter.
 *  Useful for diving by slices, without modifing the input buffer.
 *  @param str: Input string.
 *  @param str_len The length of the string.
 *  @param del: Delimiter character.
 *  @param out_slice_len: this pointer is derefenced
 *  and set with the length of the slice.
 *  @return 1 if the delimiter was found, 0 if not.
 */
int
l_strn_slice(const char *str, size_t str_len, const char del,
             size_t *out_slice_len);
#define l_str_slice(str, del, out_slice_len)                                   \
    l_strn_slice(str, strlen(str), del, out_slice_len)

/** @brief Checks whenever a string is surronded by a character.
 *  Useful for detecting quoted strings.
 *  @param str: Input string.
 *  @param str_len The length of the string.
 *  @param c: Character to check.
 *  @return 1 if it is surronded, 0 if not.
 */
int
l_strn_is_surrc(const char *str, size_t str_len, const char c);
#define l_str_is_surrc(str, c) l_strn_is_surrc(str, strlen(str), c)

/** @brief Removes a character from a string being surronded by it.
 *  Useful for removing quotes.
 *  @param str: Input string.
 *  @param str_len The length of the string.
 *  @param c: Character to check.
 *  @return Pointer to the processed string.
 */
char *
l_strn_rm_surrc(char *str, size_t str_len, const char c);
#define l_str_rm_surrc(str, c) l_strn_rm_surrc(str, strlen(str), c)

/*
 * @TODO: Doxygen
 */
char *
l_strn_trim_left(char *str, size_t str_len);
#define l_str_trim_left(str) l_strn_trim_left(str, strlen(str))

size_t
l_strn_trim_left_ro(const char *str, size_t str_len);
#define l_str_trim_left_ro(str) l_strn_trim_left_ro(str, strlen(str))

size_t
l_strn_trim_right_ro(const char *str, size_t str_len);
#define l_str_trim_right_ro(str) l_strn_trim_right_ro(str, strlen(str))

char *
l_strn_trim_right(char *str, size_t str_len);
#define l_str_trim_right(str) l_strn_trim_right(str, strlen(str))

int
l_strn_starts_with(const char *haystack, const char *needle,
                   size_t haystack_len, size_t needle_len);
#define l_str_starts_with(haystack, needle)                                    \
    l_strn_starts_with(haystack, needle, strlen(haystack), strlen(needle))

size_t
l_strn_char_cnt(const char *str, size_t str_len, const char c);

#define l_str_char_cnt(str, c) l_strn_char_cnt(str, strlen(str_len), c)

#endif /* LUCIE_LIB_INCLUDED */

/* Go visit https://github.com/lucie-cupcakes/liblucie for the latest version */
/* MIT License, more info read FILE LICENSE or visit
 * https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE */

#include "liblucie.h"
#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
l_strn_dup(const char *str, size_t s_len)
{
    assert(str);
    s_len++;
    char *ptr = calloc(s_len + 1, 1);
    return ptr ? memcpy(ptr, str, s_len) : ptr;
}

char *
l_str_catx(char *str, ...)
{
    assert(str);
    va_list ap;
    int dl = 0;
    for (dl = 0; str[dl]; dl++)
        ;
    va_start(ap, str);
    while ((char *arg = va_arg(ap, char *)))
    {
        for (int sl = 0; arg[sl]; sl++) { str[dl++] = arg[sl]; }
    }
    va_end(ap);
    str[dl] = 0;
    return str;
}

char *
l_int_base_to_str(int num, int base, char *seq, char *out_buff)
{
    int max = 1, len = 1, idx = 0;
    char *vals = vals = (seq == NULL) ? "0123456789ABCDEF" : seq;
    while ((max * base) < num)
    {
        max *= base;
        len++;
    }
    char *str = out_buff ? out_buff : calloc(1, len + 1);
    while (len--)
    {
        str[idx++] = vals[(num / max)];
        num -= (num / max) * max;
        max /= base;
    }
    return str;
}

int
l_strn_to_int_base(const char *str, size_t str_len, int base, char *seq)
{
    assert(str);
    assert(str_len);
    char *val = seq ? seq : "0123456789ABCDEF";
    int rc = 0;
    for (size_t i = 0; i < str_len; i++)
    {
        int j = 0;
        for (; j < base && str[i] != val[j]; j++)
            ;
        if (j == base)
        {
            rc = 0;
            break;
        }
        rc = (rc * base) + j;
    }
    return rc;
}

int
l_strn_slice(const char *str, size_t str_len, const char del,
             size_t *out_slice_len)
{
    assert(str);
    assert(str_len);
    assert(out_slice_len);
    size_t found = 0;
    size_t off = 0;
    for (; off < str_len && !found; off++)
    {
        found = (str[off] == del ? 1 : 0);
    }
    if (out_slice_len) { *out_slice_len = found ? off - 1 : str_len; }
    return found;
}

int
l_strn_is_surrc(const char *str, size_t str_len, const char c)
{
    assert(str);
    assert(str_len);
    return (str[str_len - 1] == c && str[0] == c) ? 1 : 0;
}

char *
l_strn_rm_surrc(char *str, size_t str_len, const char c)
{
    assert(str);
    assert(str_len);
    if (str[str_len - 1] == c && str[0] == c)
    {
        str[0] = 0;
        str[str_len - 1] = 0;
        return str + 1;
    }
    else
    {
        return str;
    }
}
char *
l_strn_trim_left(char *str, size_t str_len)
{
    assert(str);
    assert(str_len);
    size_t l_off = 0;
    for (; l_off < str_len && isspace(str[l_off]); l_off++) { str[l_off] = 0; }
    return &str[0] + l_off;
}

char *
l_strn_trim_right(char *str, size_t str_len)
{
    assert(str);
    assert(str_len);
    for (size_t i = str_len - 1; i >= str_len - 1; i--)
    {
        if (isspace(str[i]))
        {
            str[i] = 0;
            str_len--;
        }
        else
        {
            break;
        }
    }
    return str;
}

size_t
l_strn_trim_left_ro(const char *str, size_t str_len)
{
    assert(str);
    assert(str_len);
    size_t i = 0;
    for (; i < str_len && isspace(str[i]); i++)
        ;
    return i;
}

size_t
l_strn_trim_right_ro(const char *str, size_t str_len)
{
    assert(str);
    assert(str_len);
    for (size_t i = str_len - 1; i >= str_len - 1; i--)
    {
        if (isspace(str[i])) { str_len--; }
        else
        {
            break;
        }
    }
    return str_len;
}

int
l_strn_starts_with(const char *haystack, const char *needle,
                   size_t haystack_len, size_t needle_len)
{
    assert(haystack);
    assert(needle);
    assert(haystack_len);
    assert(needle_len);

    int rc = (haystack[0] && needle[0] && haystack[0] == needle[0]);
    for (size_t i = 1; rc && i < haystack_len && i < needle_len; i++)
    {
        rc = (haystack[i] == needle[i]);
    }
    return rc;
}

size_t
l_strn_char_cnt(const char *str, size_t str_len, const char c)
{
    assert(str);
    assert(str_len);
    size_t res = 0;
    for (size_t i = 0; i < str_len; i++)
    {
        if (str[i] == c) { res++; }
    }
    return res;
}

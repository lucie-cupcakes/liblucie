/* Go visit https://github.com/lucie-cupcakes/liblucie for the latest version */
/* MIT License, more info read FILE LICENSE or visit
 * https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE */

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#include <stdio.h>
#endif /* DEBUG */

#include "lucie_lib.h"

char *
l_strn_dup(const char *str, size_t s_len)
{
    char *ptr;
    s_len++;
    ptr = malloc(s_len);
    return ptr ? memcpy(ptr, str, s_len) : ptr;
}

char *
l_str_catx(char *str, ...)
{
    va_list ap;
    int dl, sl;
    char *arg;
    for (dl = 0; str[dl]; dl++)
        ;
    va_start(ap, str);
    while ((arg = va_arg(ap, char *)))
    {
        for (sl = 0; arg[sl]; sl++) { str[dl++] = arg[sl]; }
    }
    va_end(ap);
    str[dl] = 0;
    return str;
}

char *
l_int_base_to_str(int num, int base, char *seq, char *out_buff)
{
    char *str, *vals;
    int max, len, idx;
    max = 1;
    len = 1;
    idx = 0;
    vals = (seq == NULL) ? "0123456789ABCDEF" : seq;
    while ((max * base) < num)
    {
        max *= base;
        len++;
    }
    str = out_buff ? out_buff : calloc(1, len + 1);
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
    int num, i;
    size_t str_i;
    char *val;
    val = (seq == NULL) ? "0123456789ABCDEF" : seq;
    num = 0;
    for (str_i = 0; str_i < str_len; str_i++)
    {
        for (i = 0; i < base && str[str_i] != val[i]; i++)
            ;
        if (i == base)
        {
            num = 0;
            break;
        }
        num = (num * base) + i;
    }
    return num;
}

int
l_strn_slice(const char *str, size_t str_len, const char del,
             size_t *out_slice_len)
{
    int found;
    size_t off;
    found = 0;
    for (off = 0; off < str_len && !found; off++)
    {
        found = (str[off] == del ? 1 : 0);
    }
    if (out_slice_len != NULL) { *out_slice_len = found ? off - 1 : str_len; }
    return found;
}

int
l_strn_is_surrc(const char *str, size_t str_len, const char c)
{
    return (str[str_len - 1] == c && str[0] == c) ? 1 : 0;
}

char *
l_strn_rm_surrc(char *str, size_t str_len, const char c)
{
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

size_t
l_strn_trim_left_ro(const char *str, size_t str_len)
{
    size_t i = 0;
    for (; i < str_len && isspace(str[i]); i++)
        ;
    return i;
}

char *
l_strn_trim_left(char *str, size_t str_len)
{
    size_t l_off = 0;
    for (; l_off < str_len && isspace(str[l_off]); l_off++) { str[l_off] = 0; }
    return &str[0] + l_off;
}

size_t
l_strn_trim_right_ro(const char *str, size_t str_len)
{
    for (; isspace(str[str_len]); str_len--)
        ;
    return str_len;
}

char *
l_strn_trim_right(char *str, size_t str_len)
{
    for (; isspace(str[str_len]); str_len--) { str[str_len] = 0; }
    return str;
}

int
l_strn_starts_with(const char *haystack, const char *needle,
                   size_t haystack_len, size_t needle_len)
{
    int rc;
    size_t i = 1;
    rc = (haystack[0] && needle[0] && haystack[0] == needle[0]);
    for (; rc && i < haystack_len && i < needle_len; i++)
    {
        rc = (haystack[i] == needle[i]);
    }
    return rc;
}

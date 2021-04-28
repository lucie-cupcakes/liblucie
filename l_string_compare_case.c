// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

int
l_string_compare_case(char *str1, char *str2)
{
    char c;
    int res;
    while (*str1 && *str2 &&
           !(res = (((unsigned)(c = *str1 & '_') - 'A') < 26 ? c : *str1) -
                   (((unsigned)(c = *str2 & '_') - 'A') < 26 ? c : *str2)))
    {
        str1++;
        str2++;
    }
    if (!res) res = *str1 - *str2;
    return res < 0 ? -1 : !!res;
}

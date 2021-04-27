// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "strings.h"

int
tb_strcmp(char *str1, char *str2)
{
    int res;
    while (*str1 && *str2 && !(res = *str1 - *str2))
    {
        str1++;
        str2++;
    }
    if (!res) res = *str1 - *str2;
    return res < 0 ? -1 : !!res;
}

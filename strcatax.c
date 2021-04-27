// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "strings.h"

char *
tb_strcatax(char *str, int num, char **strarr)
{
    int dl, sl, tl, idx;

    sl = tb_strlen(str);
    for (idx = 0; idx < num; idx++)
    {
        tl = dl = tb_strlen(strarr[idx]);
        str = realloc(str, sl + dl);
        while (dl-- > 0) str[sl + dl] = strarr[idx][dl];
        sl += tl;
    }
    str[sl] = 0;
    return str;
}

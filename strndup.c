// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *
tb_strndup(char *srcstr, int len)
{
    char *newstr;
    if ((newstr = (char *)malloc(len + 1)))
    {
        tb_memcpy(newstr, srcstr, len);
        newstr[len] = 0;
    }
    return newstr;
}

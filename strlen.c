// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

int
tb_strlen(char *str)
{
    int len = 0;
    while (*(str++)) ++len;
    return len;
}

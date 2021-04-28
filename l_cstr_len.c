// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

l_strlen_t
l_cstr_len(const char *c_str)
{
    l_strlen_t len = 0;

    for (; c_str[len]; len++) {};
    
    return len;
}

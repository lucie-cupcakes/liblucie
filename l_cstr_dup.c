// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_cstr_dup(char *c_str) {
    char *newstr;
    int len = l_cstr_len(c_str);
    if ((newstr = (char *)malloc(len + 1))) {
        tb_memcpy(newstr, c_str, len);
        newstr[len] = 0;
    }
    return newstr;
}

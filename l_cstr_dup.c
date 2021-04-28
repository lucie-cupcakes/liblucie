// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_cstr_dup(char *c_str) {
    char *newstr;
    l_strlen_t len = l_cstr_len(c_str);
    if ((newstr = calloc(len + 1))) { l_memory_copy(newstr, c_str, len); }
    return newstr;
}

// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

l_string *l_string_take_slice(l_string *str, l_strlen_t idx, l_strlen_t len) {
    char *newstr = NULL;

    if (idx < str->length && len < (str->length - 1)) { newstr = l_string_duplicate(str + idx, len); }

    return newstr;
}

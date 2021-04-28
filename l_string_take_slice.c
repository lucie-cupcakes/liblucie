// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_string_take_slice(char *str, int idx, int len) {
    char *newstr = NULL;
    int slen = tb_strlen(str);

    if (((unsigned)idx) < slen && len < ((unsigned int)slen - 1)) { newstr = tb_strndup(str + idx, len); }
    return newstr;
}

// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

void l_strsplit(char **str, char **split, int idx) {
    char *newstr;

    if (*split) free(*split);
    newstr = tb_strndup(*str, idx);
    *split = tb_strdup(*str + idx);
    free(*str);
    *str = newstr;
}

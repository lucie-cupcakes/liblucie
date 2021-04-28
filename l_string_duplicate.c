// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_string_duplicate(char *srcstr, int len) {
    char *newstr;
    if ((newstr = calloc(len + 1))) { l_memory_copy(newstr, srcstr, len); }

    return newstr;
}

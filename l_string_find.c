// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_string_find(char *str, char *findstr) {
    int spos = 0, fpos = 0, opos;

    while (str[spos]) {
        while (str[spos] && str[spos] != *findstr) ++spos;
        opos = spos;
        while (str[spos] && findstr[fpos] && str[spos] == findstr[fpos]) {
            ++spos;
            ++fpos;
        }
        if (!findstr[fpos] &&
            (!str[spos] || str[spos] == ' ' || str[spos] == '\t' || str[spos] == '\n' || str[spos] == '\r'))
            break;
        fpos = 0;
        spos = ++opos;
    }

    return fpos ? str + opos : NULL;
}

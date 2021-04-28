// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *l_strinsert(char *str, char *insert, int idx) {
    char *newstr;
    int slen = tb_strlen(str), ilen = tb_strlen(insert);

    if (((unsigned int)idx) > slen) return NULL;
    if (ilen == 0) return str;
    newstr = malloc(slen + ilen + 1);
    tb_memcpy(newstr, str, idx);
    tb_memcpy(newstr + idx, insert, ilen);
    tb_memcpy(newstr + idx + ilen, str + idx, slen - idx + 1);
    return newstr;
}

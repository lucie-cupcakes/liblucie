// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

l_string *l_string_insert(l_string *str, l_string *insert, int idx) {
    l_string *newstr;

    if (((unsigned int)idx) > slen) return NULL;
    if (ilen == 0) return str;
    newstr = malloc(slen + ilen + 1);
    l_memory_copy(newstr, str, idx);
    l_memory_copy(newstr + idx, insert, ilen);
    l_memory_copy(newstr + idx + ilen, str + idx, slen - idx + 1);
    return newstr;
}

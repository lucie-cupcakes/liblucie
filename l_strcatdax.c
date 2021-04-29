// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

char *l_strcatdax(char *str, char delim, int num, char **strarr) {
    int dl, sl, tl, idx;

    sl = tb_strlen(str);
    for (idx = 0; idx < num; idx++) {
        tl = dl = tb_strlen(strarr[idx]);
        str[sl++] = delim;
        str = realloc(str, sl + dl);
        while (dl-- > 0) str[sl + dl] = strarr[idx][dl];
        sl += tl;
    }
    str[sl] = 0;
    return str;
}
// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

char *l_strcatx(char *str, int num, ...) {
    va_list ap;
    int dl, sl, tl;
    char *arg;

    sl = tb_strlen(str);
    va_start(ap, num);
    while (num-- > 0) {
        arg = va_arg(ap, char *);
        tl = dl = tb_strlen(arg);
        str = realloc(str, sl + dl + 1);
        while (dl-- > 0) str[sl + dl] = arg[dl];
        sl += tl;
    }
    va_end(ap);
    str[sl] = 0;
    return str;
}

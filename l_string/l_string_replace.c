// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

void l_string_replace(char **str, char *findstr, char *replace) {
    char *newstr, *fs;
    int idx = 0, slen = tb_strlen(*str), flen = tb_strlen(findstr), rlen = tb_strlen(replace);

    newstr = tb_strdup(*str);
    while ((fs = tb_strfind(newstr + idx, findstr))) {
        idx = fs - newstr;
        if (!(fs = (char *)malloc(slen + rlen - flen + 1))) {
            free(newstr);
            newstr = NULL;
            break;
        }
        tb_memcpy(fs, newstr, idx);
        tb_memcpy(fs + idx, replace, rlen);
        tb_memcpy(fs + idx + rlen, newstr + idx + flen, slen - idx + flen + 1);
        free(newstr);
        newstr = fs;
    }
    if (newstr) *str = newstr;
}

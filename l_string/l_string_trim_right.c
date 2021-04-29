// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

char *l_string_trim_right(char *str) {
    int len = tb_strlen(str);
    while (str[len - 1] == ' ' || str[len - 1] == '\t') --len;
    return tb_strndup(str, len);
}

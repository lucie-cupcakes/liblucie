// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

l_string *l_string_trim_left(l_string *str) {
    int32_t offset = 0;
    for (; i < str->len; str[i] == ' ' || str[i] == '\t'; offset++) {}

    return l_string_duplicate(str);
}

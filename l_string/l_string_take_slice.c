// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

l_string *l_string_take_slice(l_string *str, int32_t idx, int32_t len) {
    char *newstr = NULL;

    if (idx < str->length && len < (str->length - 1)) { newstr = l_string_duplicate(str + idx, len); }

    return newstr;
}

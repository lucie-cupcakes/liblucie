// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

int32_t l_string_compare(l_string *str1, l_string *str2) {
    int32_t res, i = 0;

    for (; i < str1->length && i < str2->length && !(res = str1->value[i] - str2->value[i]); i++ ) {}
    if (!res) res = str1->value[i] - str2->value[i];
    return res < 0 ? -1 : !!res;
}

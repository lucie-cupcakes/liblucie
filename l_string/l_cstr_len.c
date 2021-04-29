// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

int32_t l_cstr_len(const char *c_str) {
    int32_t len = 0;

    for (; c_str[len]; len++) {};

    return len;
}

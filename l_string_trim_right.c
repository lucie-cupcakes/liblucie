// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

l_string *l_string_trim_right(l_string *str) {
	int32_t new_len = str->length;
    while (str[new_len - 1] == ' ' || str[new_len - 1] == '\t') --new_len;
    return tb_strndup(str, new_len);
}

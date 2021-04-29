// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

l_string *l_string_create(int32_t length, const char *value) {
	l_assert(length && value);
    l_string *s = calloc(1, sizeof(l_string));
    l_assert(s);
    s->value = calloc(length, 1);
    l_assert(s->value);
    l_memory_copy(s->value, value, length);
    return s;
};

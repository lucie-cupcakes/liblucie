// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

EXTERN void
l_string_destroy(l_string *str)
{
    assert(str);
    free(str);
};

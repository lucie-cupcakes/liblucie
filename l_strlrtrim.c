// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "l_string.h"

char *
l_strlrtrim(char *str)
{
    return tb_strrtrim(tb_strltrim(str));
}

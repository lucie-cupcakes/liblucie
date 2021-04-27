// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under BSD-3-Clause - https://spdx.org/licenses/BSD-3-Clause

#include "strings.h"

char *
tb_strltrim(char *str)
{
    char *workstr = str;
    while (*workstr == ' ' || *workstr == '\t') ++workstr;

    return tb_strdup(workstr);
}

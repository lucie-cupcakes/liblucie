// Copyright (c) 2021 Lucie Cupcakes <lucie_linux@protonmail.com>
// Licensed under MIT License - https://github.com/lucie-cupcakes/liblucie/blob/main/LICENSE

#include "l_string.h"

char *l_string_trim_both(char *str) { return l_string_trim_right(l_string_trim_left(str)); }

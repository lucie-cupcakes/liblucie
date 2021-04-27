/*
 * tb_memcpy.c
 *
 * Copyright (c) 2021 Luis "Laffin" Espinoza <laffintoo@gmail.com>
 * All rights reserved.
 *
 * Licensed under BSD-3-Clause  - A copy of the license can be found in file
 * LICENSE included with the source package or you can view the full text at
 * https://spdx.org/licenses/BSD-3-Clause
 */

#include "strings.h"

void *
tb_memcpy(void *dst, void *src, size_t size)
{

#ifdef _USE_64BIT
    while (sizeof(uint64_t) <= size)
    {
        *(uint64_t *)dst = *(uint64_t *)src;
        src += sizeof(uint64_t);
        dst += sizeof(uint64_t);
        size -= sizeof(uint64_t);
    }
    if (sizeof(uint32_t) <= size)
    {
        *(uint32_t *)dst = *(uint32_t *)src;
        src += sizeof(uint32_t);
        dst += sizeof(uint32_t);
        size -= sizeof(uint32_t);
    }
#else
    while (sizeof(uint32_t) <= size)
    {
        *(uint32_t *)dst = *(uint32_t *)src;
        src += sizeof(uint32_t);
        dst += sizeof(uint32_t);
        size -= sizeof(uint32_t);
    }
#endif
    if (sizeof(uint16_t) <= size)
    {
        *(uint16_t *)dst = *(uint16_t *)src;
        src += sizeof(uint16_t);
        dst += sizeof(uint16_t);
        size -= sizeof(uint16_t);
    }
    if (size) *(uint8_t *)dst = *(uint8_t *)src;

    return dst;
}

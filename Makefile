CC ?= gcc
OUTDIR ?= $(shell pwd)
CSTD ?= -std=c89 -pedantic 
CWARN ?= -Wall -Wextra -Werror
CFLAGS ?= -Ofast -s -flto -mtune=generic 
#CFLAGS = -Og -g -D DEBUG -mtune=generic -fsanitize=address,leak

all: lucie_lib.obj
.PHONY: clean

lucie_lib.obj:
	${CC} ${CSTD} ${CWARN} ${CFLAGS} -c lucie_lib.c -o ${OUTDIR}/lucie_lib.obj

test.bin:
	${CC} ${CSTD} ${CFLAGS} -c test.c -o ${OUTDIR}/test.obj
	${CC} ${CSTD} ${CFLAGS} ${OUTDIR}/test.obj ${OUTDIR}/lucie_lib.obj -o ${OUTDIR}/test.bin

clean:
	rm -rv ${OUTDIR}/*.obj || test 1
	rm -rv ${OUTDIR}/*.bin || test 1

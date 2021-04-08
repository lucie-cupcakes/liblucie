CC ?= gcc
OUTDIR ?= $(shell pwd)
CSTD ?= -std=c89 -pedantic 
CWARN ?= -Wall -Wextra -Werror
CFLAGS ?= -Ofast -s -flto -mtune=generic 
#CFLAGS = -Og -g -D DEBUG -mtune=generic -fsanitize=address,leak

all: liblucie.o
.PHONY: clean

liblucie.o:
	${CC} ${CSTD} ${CWARN} ${CFLAGS} -c lucie_lib.c -o ${OUTDIR}/liblucie.o

test.bin:
	${CC} ${CSTD} ${CFLAGS} -c test.c -o ${OUTDIR}/test.obj
	${CC} ${CSTD} ${CFLAGS} ${OUTDIR}/test.obj ${OUTDIR}/liblucie.o -o ${OUTDIR}/test.bin

clean:
	rm -rv ${OUTDIR}/* || test 1

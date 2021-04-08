CC ?= gcc
CWD = $(shell pwd)
OUTDIR ?= bin
CSTD ?= -std=c89 -pedantic 
CWARN ?= -Wall -Wextra -Werror
CFLAGS ?= -Ofast -s -flto -mtune=generic 
#CFLAGS = -Og -g -D DEBUG -mtune=generic -fsanitize=address,leak

all: $(OUTDIR)/liblucie.o
.PHONY: clean format

$(OUTDIR):
	test -p $(OUTDIR) || mkdir -p $(OUTDIR)

$(OUTDIR)/liblucie.o: $(OUTDIR) lucie_lib.c
	${CC} ${CSTD} ${CWARN} ${CFLAGS} -o $@ -c $(CWD)/lucie_lib.c

$(OUTDIR)/test.o: $(OUTDIR) test.c
	${CC} ${CSTD} ${CFLAGS} -o $@ -c test.c

$(OUTDIR)/test: $(OUTDIR) $(OUTDIR)/liblucie.o $(OUTDIR)/test.o
	${CC} ${CSTD} ${CFLAGS} -o $@ $(OUTDIR)/liblucie.o $(CWD)/test.o

format:
	clang-format -i *.h
	clang-format -i *.c

clean:
	rm -rv $(OUTDIR)/* || test 1

CC ?= gcc
#CWD = $(shell pwd)
OUTDIR ?= bin
CSTD ?= -std=c99 -pedantic 
CWARN ?= -Wall -Wextra -Werror
CFLAGS ?= -Ofast -s -flto -mtune=generic 
#CFLAGS = -Og -g -D DEBUG -mtune=generic -fsanitize=address,leak
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))

all: $(OUTDIR) $(OUTDIR)/liblucie.o
.PHONY: clean format unit_test

$(OUTDIR):
	test -p $(OUTDIR) || mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.c
	${CC} ${CSTD} ${CWARN} ${CFLAGS} -c -o $@ $<

$(OUTDIR)/test: $(OUTDIR) $(OBJECTS)
	${CC} ${CSTD} ${CFLAGS} -o $@ $(OBJECTS) 

#This is a hack - @TODO: Fix
unit_test:
	make all
	make $(OUTDIR)/test
	./test 

format:
	clang-format -i *.h
	clang-format -i *.c

clean:
	rm -rv $(OUTDIR)/* || test 1

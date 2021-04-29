CC ?= gcc
AR ?= ar
OUTDIR ?= bin
CSTD ?= -std=c99 -pedantic 
CWARN ?= -Wall -Wextra
SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))

ifdef DEBUG
override CFLAGS ?= -D DEBUG -g -Og -mtune=generic -fsanitize=address,undefined
else
override CFLAGS ?= -D NDEBUG -s -Ofast -flto -mtune=native
endif

all: $(OUTDIR) $(OUTDIR)/liblucie.a $(OUTDIR)/liblucie.so
.PHONY: clean format unit_test

$(OUTDIR):
	test -p $(OUTDIR) || mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.c
	${CC} ${CSTD} ${CWARN} ${CFLAGS} -fPIC -c -o $@ $<

$(OUTDIR)/liblucie.a: $(OUTDIR) $(OBJECTS)
	${AR} rcs $@ $(OBJECTS)

$(OUTDIR)/liblucie.so: $(OUTDIR) $(OBJECTS)
	${CC} -shared -o $@ $(OBJECTS)

$(OUTDIR)/test: $(OUTDIR) $(OBJECTS)
	${CC} ${CSTD} ${CFLAGS} -o $@ $(OBJECTS) 

This is a hack - @TODO: Fix
unit_test:
	make all
	make $(OUTDIR)/test
	$(OUTDIR)/test 

format:
	clang-format -i *.h
	clang-format -i *.c

clean:
	rm -rv $(OUTDIR)/* || test 1

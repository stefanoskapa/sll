CC=gcc
CFLAGS=-Wall -Wextra $(OPT) -g 
OPT=-O0

LIBSRC=src/sll.c
TESTSRC=src/test.c
LIB=bin/sll.o
TESTBIN=bin/test


all: $(TESTBIN)

$(TESTBIN):$(LIBOBJ) $(TESTSRC)
	$(CC) $(CFLAGS) -o $(TESTBIN) $(LIBOBJ) $(TESTSRC)

$(LIBOBJ):$(LIBSRC)
	$(CC) $(CFLAGS) -o $(LIB) $(LIBSRC)

test:
	@bin/test
clean:
	@rm bin/*

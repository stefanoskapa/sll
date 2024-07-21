CC=gcc
CFLAGS=-Wall -Wextra $(OPT) -g 
OPT=-O0

LIBSRC=src/sll.c
LIB=bin/sll.o
TESTSRC=src/test.c
TEST=bin/test


all: $(TEST)

$(TEST):$(LIB) $(TESTSRC)
	$(CC) $(CFLAGS) -o $(TEST) $(LIB) $(TESTSRC)

$(LIB):$(LIBSRC)
	$(CC) $(CFLAGS) -c -o $(LIB) $(LIBSRC)

test:
	@bin/test
clean:
	@rm -f bin/*

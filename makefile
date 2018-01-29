OBJS = sll.o test-sll.o integer.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : test-sll sll-0-0

test-sll : $(OBJS)
		gcc $(LOPTS) $(OBJS) -o test-sll

sll-0-0 : sll.o sll-0-0.o integer.o
		gcc $(LOPTS) sll.o sll-0-0.o integer.o -o sll-0-0

integer.o : integer.c integer.h
		gcc -std=c99 $(OOPTS) integer.c

sll.o : sll.c sll.h
	gcc -std=c99 $(OOPTS) sll.c

test-sll.o :	test-sll.c sll.h
		gcc $(OOPTS) test-sll.c

sll-0-0.o :	sll-0-0.c sll.h
		gcc $(OOPTS) sll-0-0.c

test : test-sll
		./test-sll

test0 : sll-0-0
		./sll-0-0

valgrind : test-sll
		valgrind test-sll

clean	:
		rm -f *.o vgcore.* test-sll sll-0-0

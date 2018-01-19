OBJS = sll.o test-sll.o integer.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : test-sll

test-sll : $(OBJS)
		gcc $(LOPTS) $(OBJS) -o test-sll

integer.o : integer.c integer.h
		gcc $(OOPTS) integer.c

sll.o : sll.c sll.h
	gcc $(OOPTS) sll.c

test-sll.o :	test-sll.c sll.h
		gcc $(OOPTS) test-sll.c

test : test-sll
		./test-sll

valgrind : test-sll
		valgrind test-sll

clean	:
		rm -f *.o test-sll

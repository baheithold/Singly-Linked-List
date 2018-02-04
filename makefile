OBJS0 = sll-0-0.o integer.o sll.o
OBJS1 = sll-0-1.o real.o sll.o
OBJS2 = sll-0-2.o string.o sll.o
OBJS3 = sll-0-3.o integer.o sll.o
OBJS4 = sll-0-4.o integer.o sll.o
OBJS5 = sll-0-5.o real.o sll.o
OBJS6 = sll-0-6.o real.o sll.o
OBJS7 = sll-0-7.o integer.o sll.o
OBJS8 = sll-0-8.o sll.o
OBJS9 = sll-0-9.o integer.o sll.o
OBJS10 = sll-0-10.o integer.o sll.o
OBJS11 = sll-0-11.o real.o sll.o
OBJS12 = sll-0-12.o real.o sll.o
OBJS13 = sll-0-13.o integer.o sll.o
OBJS14 = sll-0-14.o integer.o sll.o
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all:	sll-0-0 sll-0-1 sll-0-2 sll-0-3 sll-0-4 sll-0-5 sll-0-6 sll-0-7 \
		sll-0-8 sll-0-9 sll-0-10 sll-0-11 sll-0-12 sll-0-13 sll-0-14

sll-0-0:	$(OBJS0)
	gcc $(LOPTS) $(OBJS0) -o sll-0-0

sll-0-1:	$(OBJS1)
	gcc $(LOPTS) $(OBJS1) -o sll-0-1

sll-0-2:	$(OBJS2)
	gcc $(LOPTS) $(OBJS2) -o sll-0-2

sll-0-3:	$(OBJS3)
	gcc $(LOPTS) $(OBJS3) -o sll-0-3

sll-0-4:	$(OBJS4)
	gcc $(LOPTS) $(OBJS4) -o sll-0-4

sll-0-5:	$(OBJS5)
	gcc $(LOPTS) $(OBJS5) -o sll-0-5

sll-0-6:	$(OBJS6)
	gcc $(LOPTS) $(OBJS6) -o sll-0-6

sll-0-7:	$(OBJS7)
	gcc $(LOPTS) $(OBJS7) -o sll-0-7

sll-0-8:	$(OBJS8)
	gcc $(LOPTS) $(OBJS8) -o sll-0-8

sll-0-9:	$(OBJS9)
	gcc $(LOPTS) $(OBJS9) -o sll-0-9

sll-0-10:	$(OBJS10)
	gcc $(LOPTS) $(OBJS10) -o sll-0-10

sll-0-11:	$(OBJS11)
	gcc $(LOPTS) $(OBJS11) -o sll-0-11

sll-0-12:	$(OBJS12)
	gcc $(LOPTS) $(OBJS12) -o sll-0-12

sll-0-13:	$(OBJS13)
	gcc $(LOPTS) $(OBJS13) -o sll-0-13

sll-0-14:	$(OBJS14)
	gcc $(LOPTS) $(OBJS14) -o sll-0-14

sll.o:	sll.c sll.h
	gcc -std=c99 $(OOPTS) sll.c

sll-0-0.o:	./testing/sll-0-0.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-0.c

sll-0-1.o:	./testing/sll-0-1.c sll.h real.h
	gcc $(OOPTS) ./testing/sll-0-1.c

sll-0-2.o:	./testing/sll-0-2.c sll.h string.h
	gcc $(OOPTS) ./testing/sll-0-2.c

sll-0-3.o:	./testing/sll-0-3.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-3.c

sll-0-4.o:	./testing/sll-0-4.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-4.c

sll-0-5.o:	./testing/sll-0-5.c sll.h real.h
	gcc $(OOPTS) ./testing/sll-0-5.c

sll-0-6.o:	./testing/sll-0-6.c sll.h real.h
	gcc $(OOPTS) ./testing/sll-0-6.c

sll-0-7.o:	./testing/sll-0-7.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-7.c

sll-0-8.o:	./testing/sll-0-8.c sll.h
	gcc $(OOPTS) ./testing/sll-0-8.c

sll-0-9.o:	./testing/sll-0-9.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-9.c

sll-0-10.o:	./testing/sll-0-10.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-10.c

sll-0-11.o:	./testing/sll-0-11.c sll.h real.h
	gcc $(OOPTS) ./testing/sll-0-11.c

sll-0-12.o:	./testing/sll-0-12.c sll.h real.h
	gcc $(OOPTS) ./testing/sll-0-12.c

sll-0-13.o:	./testing/sll-0-13.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-13.c

sll-0-14.o:	./testing/sll-0-14.c sll.h integer.h
	gcc $(OOPTS) ./testing/sll-0-14.c

integer.o:	integer.c integer.h
		gcc $(OOPTS) integer.c

real.o:	real.c real.h
		gcc $(OOPTS) real.c

string.o:	string.c string.h
		gcc $(OOPTS) string.c

test:	all
	@echo Testing Singly-Linked List
	@echo Running sll-0-0 tester...
	@./sll-0-0 > ./testing/myResults/results-0-0
	@diff ./testing/expectedResults/results-0-0 ./testing/myResults/results-0-0
	@echo
	@echo Running sll-0-1 tester...
	@./sll-0-1 > ./testing/myResults/results-0-1
	@diff ./testing/expectedResults/results-0-1 ./testing/myResults/results-0-1
	@echo
	@echo Running sll-0-2 tester...
	@./sll-0-2 > ./testing/myResults/results-0-2
	@diff ./testing/expectedResults/results-0-2 ./testing/myResults/results-0-2
	@echo
	@echo Running sll-0-3 tester...
	@./sll-0-3 > ./testing/myResults/results-0-3
	@diff ./testing/expectedResults/results-0-3 ./testing/myResults/results-0-3
	@echo
	@echo Running sll-0-4 tester...
	@./sll-0-4 > ./testing/myResults/results-0-4
	@diff ./testing/expectedResults/results-0-4 ./testing/myResults/results-0-4
	@echo
	@echo Running sll-0-5 tester...
	@./sll-0-5 > ./testing/myResults/results-0-5
	@diff ./testing/expectedResults/results-0-5 ./testing/myResults/results-0-5
	@echo
	@echo Running sll-0-6 tester...
	@./sll-0-6 > ./testing/myResults/results-0-6
	@diff ./testing/expectedResults/results-0-6 ./testing/myResults/results-0-6
	@echo
	@echo Running sll-0-7 tester...
	@./sll-0-7 > ./testing/myResults/results-0-7
	@diff ./testing/expectedResults/results-0-7 ./testing/myResults/results-0-7
	@echo
	@echo Running sll-0-8 tester...
	@./sll-0-8 > ./testing/myResults/results-0-8
	@diff ./testing/expectedResults/results-0-8 ./testing/myResults/results-0-8
	@echo
	@echo Running sll-0-9 tester...
	@./sll-0-9 > ./testing/myResults/results-0-9
	@diff ./testing/expectedResults/results-0-9 ./testing/myResults/results-0-9
	@echo
	@echo Running sll-0-10 tester...
	@./sll-0-10 > ./testing/myResults/results-0-10
	@diff ./testing/expectedResults/results-0-10 ./testing/myResults/results-0-10
	@echo
	@echo Running sll-0-11 tester...
	@./sll-0-11 > ./testing/myResults/results-0-11
	@diff ./testing/expectedResults/results-0-11 ./testing/myResults/results-0-11
	@echo
	@echo Running sll-0-12 tester...
	@./sll-0-12 > ./testing/myResults/results-0-12
	@diff ./testing/expectedResults/results-0-12 ./testing/myResults/results-0-12
	@echo
	@echo Running sll-0-13 tester...
	@./sll-0-13 > ./testing/myResults/results-0-13
	@diff ./testing/expectedResults/results-0-13 ./testing/myResults/results-0-13
	@echo
	@echo Running sll-0-14 tester...
	@./sll-0-14 > ./testing/myResults/results-0-14
	@diff ./testing/expectedResults/results-0-14 ./testing/myResults/results-0-14
	@echo

valgrind:	all
		valgrind sll-0-0
		valgrind sll-0-1
		valgrind sll-0-2
		valgrind sll-0-3
		valgrind sll-0-4
		valgrind sll-0-5
		valgrind sll-0-6
		valgrind sll-0-7
		valgrind sll-0-8
		valgrind sll-0-9
		valgrind sll-0-10
		valgrind sll-0-11
		valgrind sll-0-12
		valgrind sll-0-13
		valgrind sll-0-14

clean:
		rm -f *.o vgcore.* test-sll sll-0-0 sll-0-1 sll-0-2 sll-0-3 sll-0-3 \
		sll-0-4 sll-0-5 sll-0-6 sll-0-7 sll-0-8 sll-0-9 sll-0-10 sll-0-11 \
		sll-0-12 sll-0-13 sll-0-14

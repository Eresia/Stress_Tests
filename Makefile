all: proc

proc: testProc.c
	gcc -o proc.out testProc.c -lpthread

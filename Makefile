all: proc udp mem

proc: proc/testProc.c proc.testProc.h
	gcc -o proc.out proc/testProc.c -lpthread

udp: udp/testUDP.c udp/testUDP.h
	gcc -o udp.out udp/testUDP.c -lpthread

mem: mem/testMem.c mem/testMem.h
	gcc -o mem.out mem/testMem.c -lpthread

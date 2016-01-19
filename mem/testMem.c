#include "testMem.h"

int main(int argc, char** argv){

	int nb;
	int i;

	if(argc != 2){
		printf("Bad parameters\n");
		return 1;
	}

	nb = atoi(argv[1]);
	if(nb == 0){
		printf("Incorrect number\n");
		return 1;
	}
	for(i = 0; i < nb; i++){
		if(fork() == -1){
			#ifdef DEBUG
				printf("Fork not created\n");
			#endif
		}
	}
	test_fork();
	wait(NULL);

	return 0;
}

void test_fork(){

	unsigned long int max = 9999999999999999, i, n1 = 1, n2 = 0;
	for(i = 2; i < max; i++){
		int temp = n1 + n2;
		n2 = n1;
		n1 = temp;
	}
}

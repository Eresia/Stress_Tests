#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* launch_thread();

int main(int argc, char** argv){

	int nb;
	pthread_t* threads;
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
	threads = malloc(nb*sizeof(pthread_t));
	for(i = 0; i < nb; i++){
		pthread_create(&threads[i], NULL, launch_thread, NULL);
	}
	for(i = 0; i < nb; i++){
		pthread_join(threads[i], NULL);
	}

	return 0;
}

void* launch_thread(){

	unsigned long int max = 9999999999999999, i, n1 = 1, n2 = 0;
	for(i = 2; i < max; i++){
		int temp = n1 + n2;
		n2 = n1;
		n1 = temp;
	}
	pthread_exit(NULL);
}

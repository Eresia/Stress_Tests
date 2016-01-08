#include "testUDP.h"

int main(int argc, char** argv){
	char* ip;
	int port;
	int nb, i;
	pthread_t* threads;
	SOCKET sock;
	SOCKADDR_IN to;
	struct hostent* hostinfo;

	if(argc != 4){
		printf("Incorrect arguments\n");
		return 1;
	}

	ip = argv[1];
	port = atoi(argv[2]);
	nb = atoi(argv[3]);
	if(nb == 0){
		printf("Incorrect threads number\n");
		return 1;
	}

	if(port == 0){
		printf("Incorrect port number\n");
		return 1;
	}


	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == INVALID_SOCKET)
	{
	    return 0;
	}

	hostinfo = gethostbyname(ip);
	if (hostinfo == NULL)
	{
	    fprintf (stderr, "Unknown host %s.\n", ip);
	    return 0;
	}

	threads = malloc(nb*sizeof(pthread_t));

	to.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
	to.sin_port = htons(port);
	to.sin_family = AF_INET;

	Info info;
	info.sock = sock;
	info.info = &to;

	if(sendto(sock, "test", strlen("test"), 0, (SOCKADDR *)&to, (socklen_t) sizeof(to)) < 0)
	{
		printf("Impossible to send data\n");
		return 1;
	}

	for(i = 0; i < nb; i++){
		pthread_create(&threads[i], NULL, envoie, &info);
	}

	for(i = 0; i < nb; i++){
		pthread_join(threads[i], NULL);
	}

}

void* envoie(void* info_void){

	Info* info = (Info*) info_void;
	char* buffer = calloc(2000, sizeof(char));
	unsigned long int i;
	int tosize = sizeof(*info->info);

	for(i = 0; i < 1400; i++){
		buffer[i] = 't';
	}

	for(i = 0; i < 9999999; i++){
		if(sendto(info->sock, buffer, strlen(buffer), 0, (SOCKADDR *)info->info, (socklen_t) tosize) < 0)
		{
		    printf("Nothing send\n");
		}
	}
	pthread_exit(NULL);
}

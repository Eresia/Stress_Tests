#ifndef TEST_UDP
#define TEST_UDP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Threads include
#include <pthread.h>

//Socket include
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

typedef struct Info Info;
struct Info{
	SOCKET sock;
	SOCKADDR_IN* info;
};

void* envoie(void* v);

#endif

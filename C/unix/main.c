#include <stdio.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv) {
	int socketfd;
	printf("%d\n", errno);
	//TCP
	//if ((socketfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {

	//UDP
	if ((socketfd = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
		printf("error.\n");
		return 0;
	}
	printf("socketfd: %d\n", htonl(socketfd));
	printf("%d\n", fcntl(socketfd, F_GETFL));
	close(socketfd);

	//shutdown(socketfd, SHUT_RDWR);

	return 0;
}

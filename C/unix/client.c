#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/tcp.h>
#include <stdarg.h>
#include "connector.h"

#define HOST "127.0.0.1"
#define PORT 6379

int main(){
    //创建套接字
    int sock = 0;
	if ((sock = createClientSocket(HOST, PORT)) == -1) {
		exit(1);
	}

    char send_buffer[] = "*2\r\n$3\r\nget\r\n$4\r\nname\r\n";
	int nwrite = write(sock, send_buffer, sizeof(send_buffer));
	printf("%d %d %d\n", nwrite, sizeof(send_buffer), EINTR);

	//读取服务器传回的数据
	char buffer[1024];
	int read_size;
	do {
    	read_size = read(sock, buffer, sizeof(buffer)-1);
    	printf("Message form server: %s\n", buffer);
    } while (0);
   
    //关闭套接字
    close(sock);
    return 0;
}



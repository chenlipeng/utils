#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOST "127.0.0.1"
#define PORT 1234

int main(){
    //创建套接字
    int serv_sock = createServerSocket(HOST, PORT);

    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);

    int clnt_sock;
	int sequence = 0;
    while ((clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size)) != -1) {
    	//向客户端发送数据
    	printf("%d\n", ++sequence);
		pid_t pid = fork();
		if (pid == 0) {
    		char str[] = "Hello World!Hello World!Hello World!Hello World!Hello World!Hello World!";
    		int ret = write(clnt_sock, str, sizeof(str));
			printf("%d\n", ret);
			//dosomething.
			printf("childPid: %d\n", getpid());
			//关闭套接字
			close(clnt_sock);
			exit(0);
		} else {
			printf("parentPid: %d\n", getpid());
		}
	}
   
    close(serv_sock);

    return 0;
}

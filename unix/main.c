#include "apue.h"
#include "ls.h"
#include <sys/wait.h>
#include <limits.h>

#define BUFSIZE 4096

void sig_int(int signo);

int main(int argc, char **argv) {

	printf("%d %d %d %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, open_max());
	return;

	printf(
		"CHAR_BIT: %d\n"
		"CHAR_MAX: %d\n"
		"CHAR_MIN: %d\n"
		"SCHAR_MAX: %d\n"
		"SCHAR_MIN: %d\n"
		"UCHAR_MAX: %d\n"
	, CHAR_BIT, CHAR_MAX, CHAR_MIN, SCHAR_MAX, SCHAR_MIN, UCHAR_MAX);
	return 0;


	//printf("gid: %d, uid: %d\n", getgid(), getuid());
	//return 0;

	//fprintf(stderr, "EACCES: %s\n", strerror(ENOENT));
	//perror(argv[0]);
	//return 0;

	//int self_errno;
	//for (self_errno = 0; self_errno < 512; ++self_errno) {
	//	printf("%s\n", strerror(self_errno));
	//}

	//return 0;

	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR) {
		err_sys("signal error.");
	}

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0) {
			err_sys("fork error.");
		} else if (pid == 0) {
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("waitpid error.");
		}
		printf("%% ");
	}
	return 0;

	printf("pid: %ld\n", getpid());
	return 0;

	char c;
	while ((c = getc(stdin)) != EOF) {

		if (putc(c, stdout) == EOF) {
			err_sys("output error.");
		}
	}
	return 0;

	//int n;
	//char buf[BUFSIZE];

	//while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
	//	if (write(STDOUT_FILENO, buf, n) != n) {
	//		err_sys("Write error.");
	//	}
	//}

	//if (n < 0) {
	//	err_sys("Read error.");
	//}


	//if (argc != 2)
	//	err_quit("usage: ls directory_name");

	//printf("%s\n", argv[1]);
	//readdir_recursive(argv[1], 0);
	//return 0;
}

void sig_int(int signo) {
	printf("interrutp\n%%");
}

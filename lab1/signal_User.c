#include <signal.h>
#include <stdio.h>

void err_sys(const char* x);
void err_dump(const char* x, int signo);
static void sig_usr(int); 
/* one handler for both signals */

int main(void){
	pid_t pid; 
	int i;

	printf("%d\n", getpid());

	pid = fork();

	if(pid != 0) {	
		exit(0);
	}
	printf("%d\n", getpid());

//문제1------------------------------------------------
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2\n");
//문제2------------------------------------------------
	if (signal(SIGINT, sig_usr) == SIG_ERR)
			printf("can't catch SIGINT\n");
	if (signal(SIGQUIT, sig_usr) == SIG_ERR)
			printf("can't catch SIGQUIT\n");
	if (signal(SIGSTOP, sig_usr) == SIG_ERR)
			printf("can't catch SIGSTOP\n");

	for ( ; ; ) pause();
}

static void sig_usr(int signo) { 
/* argument is signal number */

	if (signo == SIGUSR1)
		printf("절전모드\n");
	else if (signo == SIGUSR2)
		printf("일반모드\n");
	else if (signo == SIGINT)
		printf("Received : SIGINT\n");
	else if (signo == SIGSTOP)
		printf("Received : SIGSTOP\n");
	else if (signo == SIGQUIT)
		printf("Received : SIGQUIT\n");
	return;
}
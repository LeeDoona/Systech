#include <signal.h>

static void sig_child(int);

int main(void) {

	pid_t pid; 
	int i;
		printf("before signal\n");
	signal(SIGCHLD, sig_child);
		printf("task\n");
	pid = fork();
		printf("bye!\n");
	if (pid == 0) {
		sleep(1);
		exit(0);
	}

	while(1) { i = i; }
}

static void sig_child(int signo){
	pid_t pid; int status;
	pid = wait(&status);
	printf("child %d finished\n", pid);
}
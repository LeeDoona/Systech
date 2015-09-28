#include <signal.h>
static void sig_fpe(int);

int main(void){
	pid_t pid; int i;
	signal(SIGFPE, sig_fpe);
	i = i/0;
}

static void sig_fpe(int signo){
	pid_t pid; 
	int status;
	printf("Divide by 0 Error\n");
	/* routine that saves all variables*/
	exit(1);
}
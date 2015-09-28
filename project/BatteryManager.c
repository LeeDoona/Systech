#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>			//for signal

#define DEVICE_FILE_NAME "/dev/chr_dev" // 디바이스 파일

static void sig_usr(int);			//signo handler


// argv 값을 받아 디바이스 파일의 IOCTL cmd 값으로 사용
int main(int argc, char *argv[]) {
	int device;
	char wbuf[128] = "80";
	char rbuf[128];
	int n = atoi(argv[1]);
	//make demon process
	pid_t pid, ppid/*program pid*/;

	
	pid = fork();
	if(pid != 0) exit(0);
	printf("process running: %d", getpid());

	device = open(DEVICE_FILE_NAME, O_RDWR | O_NDELAY);

	if (device >= 0) {

		printf("Device file Open\n");
		ioctl(device, n); // argv 값을 디바이스 파일에 cmd 값으로 전달
		
		read(device, rbuf, 10);
		printf("read value is %s\n", rbuf);

		write(device, wbuf, 10); // wbuf 값을 디바이스 파일에 전달
		printf("Write value is %s\n", wbuf);

	} else
		perror("Device file open fail");

	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1");
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2");

	while(1) pause();

	return 0;
}

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("절전\n");
	else if(signo == SIGUSR2)
		printf("정상\n");
	return;
}
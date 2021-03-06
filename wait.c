#include <stdlib.h>  /*define exit()*/
#include <unistd.h>  /*for k() and getpid()*/
#include <stdio.h> /*for printf()*/
#include <sys/wait.h>

int main(int argc, char  **argv)
{
	int pid;  /*process ID*/
	
	switch (pid=fork())
	{
		case 0:  /*fork returns 0 to the child */
		printf("I am child process: pid=%d\n", getpid());
		break;

		default:  /*fork returns a pid to the parent */
		wait(NULL);
		printf("I am parent process: pid=%d, child pid=%d\n", getpid(), pid);
		break;

		case -1:    /*something went wrong */
		perror("fork");
		exit(1);
	}
	exit(0);
}



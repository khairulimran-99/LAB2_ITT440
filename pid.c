#include <stdlib.h> /*define exit() */
#include <unistd.h> /*fork() ad getpid() */
#include <stdio.h> /* for printf() */

int main (int argc, char **argv)
{
	int pid;  /*process ID */
	
	switch(pid = fork())
	{
		case 0: /* a fork return 0 to the child */
		printf("I am child process: pid=%d\n", getpid());
		break;

		default:  /*a frok return pid to the parent*/
		printf("I am the parent process: pid=%d, child pid =%d\n", getpid(), pid);
		break;
		
		case -1: /*something went wrong */
		perror("fork");
		exit(1);
	}
	exit(0);
}



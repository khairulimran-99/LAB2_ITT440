#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void childTask()
{
	char name[10];
	printf("Name: ");
	scanf("%s", name);
	printf("Your name: %s\n", name);
	exit(0);
}

void parentTask()
{
	printf("Job is Done!!\n\n");
}

int main(void)
{
	for(int i=0; i<4; i++)
	{
		int a = fork();

		if (a == 0)
		{
			childTask();
			return (EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			parentTask();
		}
	}
}

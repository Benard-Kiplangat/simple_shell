#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define PID_MAX 4194304

/**
 * main - a function to print pid and ppid
 *
 * Return: always 0
 */

int main(void)
{
	pid_t mypid = getpid();
	pid_t myppid = getppid();

	printf("My PID: %u.\n", mypid);
	printf("My PPID: %u.\n", myppid);
	printf("Maximum PID value is: %u.\n", PID_MAX);
	return (0) ;
}

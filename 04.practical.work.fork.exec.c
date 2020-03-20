#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

int main()
{
	int pid1, pid2;
	pid1 = fork();
	pid2 = fork();
	if (pid1 == 0) 
	{
		printf("I am child 1 after fork(), launching ps -ef\n");
		char *args[]= {"/bin/ps", "-ef" , NULL};
		execvp("/bin/ps", args);
	}
	else if (pid2==0)
	{
		printf("I am child 2 after fork(), launching ps -ef\n");
		char *args[]= { "/bin/free", "-h" , NULL};
		execvp("/usr/bin/free", args);
	}
	else if (pid1!=0 && pid2!=0)
	{
		printf("I am parent after fork(), child is %d %d\n", pid1,pid2);
	}	
	return 0;
}

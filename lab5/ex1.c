#include <stdio.h>
#include <stdlib.h>

void main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        printf("Child Process ID : %d ", &getpid());
    }
}

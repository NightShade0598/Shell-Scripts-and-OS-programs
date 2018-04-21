
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	pid_t child = fork();
	int i, j;
	int status;

	if(!child)
	{
		printf("Sorted strings.\n");
		for(i = 1; i < argc - 1; i++)
		{
			for(j = i + 1; j < argc; j++)
			{
				if(strcmp(*(argv + i), *(argv + j)) > 0)
				{
					char *temp = *(argv + i);
					*(argv + i) = *(argv + j);
					*(argv + j) = temp;
				}
			}
		}

		for(i = 1; i < argc; i++)
			printf("%s ", *(argv + i));
	}

	else if(child > 0)
	{
		wait(&status);
		printf("\nUnsorted strings.\n");
		for(i = 1; i < argc; i++)
			printf("%s ", *(argv + i));
		printf("\n");
	}

	else
	{
		printf("Fork failed.");
	}

	return 0;
}

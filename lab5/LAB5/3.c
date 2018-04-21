#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int n, i, j, status;
	char a[10][10], temp[10];
	scanf("%d", &n);

	gets(a[0]);

	for(i = 0; i < n; i++)
	{
		gets(a[i]);
	}

	pid_t child = fork();

	if(child > 0)
	{
		//parent simply waits
		wait(&status);
		printf("Done waiting.\n");
		for(i = 0; i < n; i++)
			printf("%s ", a[i]);
		printf("\n");
	}

	else if(child < 0)
	{
		//fork failed
		printf("Fork failed.\n");
	}

	else
	{
		//child process
		child = fork();

		if(child > 0)
		{
			//does bubble sort
			printf("Bubble Sort\n");
			for(i = 0; i < n - 1; i++)
			{
				for(j = i + 1; j < n; j++)
				{
					if(strcmp(a[i], a[j]) > 0)
					{
						strcpy(temp, a[i]);
						strcpy(a[i], a[j]);
						strcpy(a[j], temp);
					}
				}
			}

			for(i = 0; i < n; i++)
				printf("%s ", a[i]);
			printf("\n");
		}

		else if(child < 0)
		{
			//fork failed
			printf("Failed.\n");
		}

		else
		{
			//does selection sort
			printf("Selection sort\n");
			for(i = 0; i < n - 1; i++)
			{
				char min[10];
				strcpy(min, a[i]);
				int pos = i;
				for(j = i + 1; j < n; j++)
				{
					if(strcmp(a[j], min) < 0)
					{
						strcpy(min, a[j]);
						pos = j;
					}
				}
				strcpy(temp, a[i]);
				strcpy(a[i], a[pos]);
				strcpy(a[pos], temp);
			}

			for(i = 0; i < n; i++)
				printf("%s ", a[i]);
			printf("\n");
		}
	}

	return 0;
}



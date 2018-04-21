#include<stdio.h>
#include<stdlib.h>
int main()
{
    void FCFS();
    void CLOOK();
    void CSCAN();
    void SCAN();
    void SSTF();
    int ch;
    printf("Enter 1.FCFS 2.CLOOK 3.CSCAN 4.SCAN 5.SSTF : ");
    scanf("%d",&ch);
    switch(ch){
        case 1 : FCFS(); break;
        case 2 : CLOOK(); break;
        case 3 : CSCAN(); break;
        case 4 : SCAN(); break;
        case 5 : SSTF(); break;
        default : break;
    }
}
void FCFS()
{
    int head,seek=0,n,i,j,temp;

	printf("\nEnter the size of Queue : ");  scanf("%d",&n);
	int *queue = (int *) calloc(n, sizeof(int));
	printf("Enter the Queue\n");
	for(i=0;i<n;i++)
		      scanf("%d",&queue[i]);
	printf("Initial Head Position : ");  scanf("%d",&head);

	queue[0]=head;

	printf("Movements : ");
	for(j=0;j<=n-1;j++){
		int diff=abs(queue[j+1]-queue[j]);
		seek+=diff;
		printf("%3d\t",queue[j]);
	}
	printf("\nTotal Head Movement : %d\n",seek);


}
void CLOOK()
{
    int i, j, sum = 0, n;
    int d[100];
    int disk, lim;   //loc of head
    int temp, max;
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);

    printf("Initial Head Position : ");  scanf("%d", &disk);
    printf("Enter Cylinder Limit : ");	scanf("%d", &lim);
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++)    // sorting disk locations
    {
        for (j = i; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n];
    for (i = 0; i < n; i++)   // to find loc of disc in array
    {
        if (disk == d[i]) {
            dloc = i;
            break;
        }

    }
    sum = 0;
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    disk=d[n-1];
    printf("%d\t", disk);
    for (i = n-2; i > dloc+1; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("\nmovement of total cylinders %d", sum);

}
void CSCAN()
{
    int i, j, sum = 0, n;
    int d[100];
    int disk, lim;   //loc of head
    int temp, max;
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);

    printf("Initial Head Position : ");  scanf("%d", &disk);
    printf("Enter Cylinder Limit : ");	scanf("%d", &lim);
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++)    // sorting disk locations
    {
        for (j = i; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n];
    for (i = 0; i < n; i++)   // to find loc of disc in array
    {
        if (disk == d[i]) {
            dloc = i;
            break;
        }

    }
    sum = 0;
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("0\t");
    sum += disk;
    disk=lim-1;
    for (i = n-1; i > dloc+1; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("\nmovement of total cylinders %d", sum);

}
void SCAN()
{
    int i, j, sum = 0, n;
    int d[100];
    int disk;   //loc of head
    int dloc;   //loc of disk in array
    printf("Enter Size of Queue : ");    scanf("%d", &n);
    printf("Enter the Queue\n");
    for (i = 0; i < n; i++)   scanf("%d", &d[i]);

    printf("Initial Head Position : ");  scanf("%d", &disk);
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++)    // sorting disk locations
        for (j = i; j < n; j++)
            if (d[i] > d[j]) {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }

    for (i = 0; i < n; i++)   // to find loc of disc in array
        if (disk == d[i]) {
            dloc = i;
            break;
        }

    sum = 0;
    for (i = dloc; i >= 0; i--) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("0\t");
    sum += disk;
    disk=0;
    for (i = dloc + 2; i < n; i++) {
        printf("%d\t", d[i]);
        sum += abs(disk - d[i]);
        disk = d[i];
    }
    printf("\nmovement of total cylinders %d", sum);

}
void SSTF()
{
    int head,seek=0,n,i,j,temp;

	printf("\nEnter the size of Queue : ");  scanf("%d",&n);
	int *queue = (int *) calloc(n, sizeof(int));
	int *t = (int *) calloc(n, sizeof(int));
	printf("Enter the Queue\n");
	for(i=0;i<n;i++)
		      scanf("%d",&queue[i]);
	printf("Initial Head Position : ");  scanf("%d",&head);

     for(i=1;i<n;i++)
        t[i]=abs(head-queue[i]);
     for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
           if(t[i]>t[j])
           {
	            temp=t[i];
                t[i]=t[j];
                t[j]=temp;
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
           }

	printf("Movements : %3d\t", head);
	for(i=1;i<n;i++){
		seek=seek+abs(head-queue[i]);
		head=queue[i];
		printf("%3d\t",head);
	}
	printf("\nTotal Head Movement : %d\n",seek);
}

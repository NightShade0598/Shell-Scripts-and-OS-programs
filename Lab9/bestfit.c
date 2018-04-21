#include<stdio.h>
#include<limits.h>
void main()
{
	int h[20],p[20],i,j,nh,np;
	printf("Enter Number of Memory Partitions : ");
	scanf("%d",&nh);
	for(i=0;i<nh;i++)
	{
		printf("Enter Size of Partition %d : ",i);
		scanf("%d",&h[i]);
	}	
	
	printf("\nEnter Number of Processes : ");
	scanf("%d",&np);
	
	for(i=0;i<np;i++)
	{
		printf("Size of Process %d : ",i);
		scanf("%d",&p[i]);
	}
	
	int min, x=0,flag,flag2;
	
	for(i=0;i<np;i++)
	{
		flag=0;
		flag2=0;
		min=INT_MAX;
		x=0;
		for(j=0;j<nh;j++)
		{
			if(p[i]>h[j] && flag2==0) flag=1;
			if(p[i]<=h[j])
			{
				flag = 0;
				flag2=1;
				if(h[j]<min && h[j]>0)	
				{
					min = h[j];
					x=j;
				}
			}
		}
		if(flag==1)	
			continue;
		printf("Process %d = Partition %d\n",i,x);
		printf("Process Size %d -> Partition Size %d\n",p[i],h[x]);
		printf("Remaining in Partition %d = %d\n\n",x,(h[x]=h[x]-p[i]));
		h[x]=h[x]-p[i];
    		p[i]=INT_MIN;
    		
 	}
	for(j=0;j<np;j++)
		if(p[j]!=INT_MIN)		
			printf("Process %d is unallocated.\n",j);
		
}

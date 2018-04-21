#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter the max range : ");//scan
    scanf("%d",&max);
    printf("Enter the number of entries in the queue : ");
    scanf("%d",&num);
    printf("Enter Queue elements : 0");
    for(i=0;i<num;i++)
        scanf("%d",&ele[i]);
    printf("Enter the head value : ");
    scanf("%d",&head);
    for(i=0;i<num;i++)
    {
        if(ele[i]>=head){
            queue1[k]=ele[i];
            k++;
        }
        else if(ele[i]<head){
            queue2[l]=ele[i];
            l++
        }
    }
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(queue1[i]>queue1[j]){
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(queue2[i]>queue2[j]){
                temp=queue1[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }
    queue[0]=head;
    for(i=0,j=0;i<num;i++,j++)
    queue[j]=queue1[i];

    queue[j]=max-1;
    for(i=l-1;i>0;i--,j++)
        queue[j]=queue2[i];

    for(i=0;i<j;i++){
        printf(" ");
    }


}

#include<stdio.h>
void optimal()
{
int interval[25];
      int pages, total_frames, page_faults = 0;
      int m, n, temp, flag, found;
      int position, maximum_interval, previous_frame = -1;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      int *reference_string = malloc(pages*(sizeof(int)));
      printf("\nEnter Values of Reference String\n");
      for(m = 0; m < pages; m++)
      {
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      int *frames = malloc(total_frames*(sizeof(int)));
      for(m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            flag = 0;
            for(n = 0; n < total_frames; n++)
            {
                  if(frames[n] == reference_string[m])
                  {
                        flag = 1;
                        printf("\t");
                        break;
                  }
            }
            if(flag == 0)
            {
                  if (previous_frame == total_frames - 1)
                  {
                        for(n = 0; n < total_frames; n++)
                        {
                              for(temp = m + 1; temp < pages; temp++)
                              {
                                    interval[n] = 0;
                                    if (frames[n] == reference_string[temp])
                                    {
                                          interval[n] = temp - m;
                                          break;
                                    }
                              }
                        }
                        found = 0;
                        for(n = 0; n < total_frames; n++)
                        {
                              if(interval[n] == 0)
                              {
                                    position = n;
                                    found = 1;
                                    break;
                              }
                        }
                  }
                  else
                  {
                        position = ++previous_frame;
                        found = 1;
                  }
                  if(found == 0)
                  {
                        maximum_interval = interval[0];
                        position = 0;
                        for(n = 1; n < total_frames; n++)
                        {
                              if(maximum_interval < interval[n])
                              {
                                    maximum_interval = interval[n];
                                    position = n;
                              }
                        }
                   }
                   frames[position] = reference_string[m];
                   printf("Fault\t");
                   page_faults++;
            }
            for(n = 0; n < total_frames; n++)
            {
                  if(frames[n] != -1)
                  {
                        printf("%d\t", frames[n]);
                  }
            }
            printf("\n");
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_faults);


}
void fifo()
{
    int i,j,n,no,k,avail,count=0;

    printf("Enter the Number of pages : ");
    scanf("%d",&n);
    int *a = malloc(n*(sizeof(int)));
    printf("Enter the page Number : ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&no);
    int *frame = malloc(no*(sizeof(int)));
    for(i=0;i<no;i++)
        frame[i]= -1;
        j=0;
    printf("\tReference String\t Page Frames\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
            if (avail==0)
            {
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
            }
            printf("\n");
    }
    printf("Page Fault Is %d",count);
}
int main()
{
    void optimal();
    void fifo();
    printf("Enter 1 for FIFO and 2 for OPTIMAL : ");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
        fifo();
    else if(ch==2)
        optimal();
    else
        printf("Invalid Option");
        return 0;
}

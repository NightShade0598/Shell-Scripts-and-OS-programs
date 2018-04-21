#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ch;
    cout<<("Enter the choice : 1.PSJF 2.RR 3.NPS");
    cin>>ch;
    if(ch==1)
        psjf();
    else if(ch==2)
        rr();
    else if(ch==3)
        nps();
    else
        cout<<("Invalid Option");
}
void psjf()
{
    int nop;
    int i;
    cou<<("Enter the Number of processes : ");
    cin>>nop;
    int burst_time[nop],process_priority[nop];
    cout<<("Enter Process Time and Priority : ");
   for(i=0;i<nop;i++)
    {
      cout<<("\nProcess no %d : ",i+1);
      cin>>burst_time[i]>>process_priority[i];
    }
}

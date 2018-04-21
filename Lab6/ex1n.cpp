#include<iostream>
using namespace std;
int nop;
struct process
{
    int att,bt,wt,tt,prior;
}p[10];

void display()
{
    for(int i=0;i<nop;i++)
    {
        cout<<p[i].att<<"\t"<<p[i].bt<<"\t"<<p[i].prior<<endl;
    }
}

void sortbyat()
{
    struct process temp;
    for(int i=0;i<nop;i++)
    {
        for(int j=0;j<nop;j++)
        {
            if(p[i].att<p[j].att)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

}
void nps(){
    cout<<("Enter Arrival Time,Process Time and Priority : ");
    for(int i=0;i<nop;i++)
    {
        cin>>p[i].att>>p[i].bt>>p[i].prior;
    }
    for(int i=0;i<nop;i++){
        for(int j=0;j<nop;j++){

        }
    }
    sortbyat();
    display();
    for(int i=0;i<nop;i++){

    }
}
void psjf()
{

}
void rr()
{

}

int main()
{
    int ch;
    cout<<"Enter the choice : 1.PSJF 2.RR 3.NPS : ";
    cin>>ch;
    cout<<"Enter the number of processes : ";
    cin>>nop;
    if(ch==1)
        psjf();
    else if(ch==2)
        rr();
    else if(ch==3)
        nps();
    else
        cout<<"Invalid Option";
}

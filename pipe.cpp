#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
#define SIZE sizeof(int)


int main()
{   int p[2], i,n,sum=0,num,input;
    float avg;
    cout<<"Enter number of entries:";
    cin>>n;
    if (pipe(p) < 0)
        exit(1);
    cout<<"Enter numbers:";
    for(i=0;i<n;i++)
    { cin>>num;
    write(p[1], &num, SIZE);
}

    for (i=0; i<n;i++)
{   read(p[0], &input, SIZE);
   sum+=input;
    }
    cout<<"Sum:"<<sum;
    avg=sum/n;
    cout<<"\nAverage:"<<avg;
    return 0;
}

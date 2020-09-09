#include<bits/stdc++.h>

using namespace std;

int main()
{
    int numprocess, i,j;
    cout<<"Enter Number of Processes: ";
    cin>>numprocess;

    int exetim[numprocess];
    int arrvtim[numprocess];


    cout <<" Enter the execution time respectively : ";
    for(i=1; i<=numprocess; i++)
    {
        cin>> exetim[i];
    }

      cout <<" Enter the arrival time respectively : ";
        for(j=1; j<=numprocess; j++)
    {
        cin >> arrvtim[j];
    }

    cout<< "Enter the Algorithm you want to use:"<<"\n";
    cout<< "1. First Come First Serve Scheduling"<<"\n";
    cout<< "2. Shortest Job First Scheduling"<<"\n";
    cout<< "3. Priority Scheduling "<<"\n";
    cout<< "4. Round Robin Scheduling "<<"\n";

    int ch;
      cin>>ch;

      switch(ch){
      case: ""


      }

}

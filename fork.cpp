#include <iostream>
#include <unistd.h>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define cons 1e9+7

using namespace std;

int main()
{

    int n,k;
    cout<<"Enter the number"<<" ";
    cin>>n;

    k= fork();

    if(k>0)
    {
        cout<<"Parent process: "<<"\n";

     for(int i=1; i<=n; i+=2)
     {
         cout<<i<<" ";
     }
     cout<<"\n";
     cout<<"child process:"<<"\n";
     for(int i=2; i<=n; i+=2)
     {
         cout<< i<<" ";
     }
    }
}

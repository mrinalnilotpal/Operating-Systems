#include<vector>
#include<bits/stdc++.h>
#include<fstream>

#define lli long long int

using namespace std;

struct Student
{   int Roll;
    int Mark;
    string Name;
}t,s[70];

void create()
{ fstream fout;
    fout.open("student_marks.csv", ios::out | ios::app );
  int i, Roll, Mark;
   string Name;
for (i = 1; i <=70; i++)
{ cout<<"Student Num "<<i<<"\n";
   cout<<"Enter Roll :";
   cin>>s[i].Roll;
   cout<<"Enter Name:";
   cin>>s[i].Name;
   cout<<"Enter Marks:";
   cin>>s[i].Mark;
fout<< s[i].Roll << ", " << s[i].Name << ", " << s[i].Mark <<"\n";
}
}

void calculate()
{   fstream fin;
    fstream fout;
    char Grade;int i,Roll;
    fin.open("student_marks.csv", ios::in);
    fout.open("student_grades.csv", ios::out | ios::app);
    for (i = 1; i < 70; i++)
{ fin.read((char*)&s[i],sizeof(s[i]));
   if(s[i].Mark>90)
  Grade='A';
else if(s[i].Mark>80)
  Grade='B';
else if(s[i].Mark>70)
  Grade='C';
else if(s[i].Mark>60)
  Grade='D';
else
  Grade='E';
fout << i << ", " << Grade <<"\n";
}
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    create();
    calculate();
}

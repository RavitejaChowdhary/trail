#include<iostream>
using namespace std;
int count(int p)
{
    int total=0;
    if(p==1)
    {
        return 1;
    }
    else
    {
       for(int i=1;i<p;i++)
       {
         total += count(i)*count(p-i);
       }
    }
    return total;
}
int main()
{
    cout<<count(3);
}
#include<iostream>
#include<cstring>
using namespace std;
  
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        long long a=1;
        for(int i=0;i<m;i++)
        {
            a*=2;
        }
        cout<<a-1<<endl;
    }
}
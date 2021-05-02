#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    long long a[60];
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=60;i++)
    a[i]=a[i-2]+a[i-1]; 
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        cout<<a[m];
        cout<<endl;
    }
     
}
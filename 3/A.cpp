#include<iostream>
#include<algorithm>
using namespace std;
  
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m,n;
        cin>>m;
        cin>>n;
        int a[1000];
          
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        for(int i=m;i<n+m;i++)
        {
            cin>>a[i];
        }
        sort(a,a+m+n);
        for(int i=0;i<n+m;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
          
    }
 }
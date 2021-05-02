#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int t=0;
    sort(a,a+n);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        {
            int l=i,r=n-1;
            while(l<r)
            {
                int mid = (l+r+1)/2;
                if(a[mid]>=a[i]+a[j]) r=mid-1;
                else l=mid;
            }
            t+=l-i;
        }
    cout<<t<<endl;
 
}
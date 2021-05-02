#include<iostream>
#include<cmath>  
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
 
int n,c;
int fun(int mid) 
{
 
    int cnt=0,sum=0;
    for(int i=0; i<n; i++)
    {
        if(sum+a[i]<=mid)
        {
            sum+=a[i];
 
        }
        else
        {
     
            sum=a[i];
            cnt++;  
        }   
    }
     
    if(cnt>=c)                   
    {
        return 1;   
    }
    else
    {
        return 0;   
    }   
}
  
int main()
{
     
    while(scanf("%d%d",&n,&c)==2) 
    { 
        int r=0,l=0,mid=0; 
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++) 
        {
            scanf("%d",&a[i]);
            r+=a[i];
            l=max(l,a[i]);
        }
         
         
        while((r>=l))
        {
            mid=(l+r)/2;     
            if(fun(mid))            //多了 
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
         
    cout<<l<<endl;
    }
}
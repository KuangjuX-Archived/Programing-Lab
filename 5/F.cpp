#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,x,y,t,s,a[1001][1001],dp[1001][1001];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    register int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        for(i=1;i<=2*n-2;i++)
        {
            cin>>x>>y;
            if(x==n&&y==n&&x+y-2<i)
            {
                cout<<"No"<<endl;
            }
            if(x+y-2>i)
            {
                a[x][y]=1;
            }
        }
        dp[1][1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if((dp[i][j-1]==1 || dp[i-1][j]==1) && a[i][j]!=1)
                {
                    dp[i][j]=1;
                }
            }
        }
        if(dp[n][n])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
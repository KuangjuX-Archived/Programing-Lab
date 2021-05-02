#include <iostream>
#include <cstdio>
#define inf 0x3f3f3f
using namespace std;
 
int mp[105][105];
void floyd(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]>mp[i][k]+mp[k][j])
                {
                    mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
    }
}
int main ()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            mp[i][i]=0;
            for(int j=0;j<i;j++)
            {
                mp[i][j]=mp[j][i]=inf;
            }
        }
        int a,b;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            mp[a][b]=mp[b][a]=1;
        }
        floyd(n);
        int flag;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]>7)
                {
                    flag=1;
                    j=i=n;
                }
            }
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }
 }
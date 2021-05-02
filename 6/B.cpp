#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
const int MAX=1010;
int ru[MAX],d[MAX][MAX],n,m,a,b,ans[MAX];
string s;
void topsort()
{
    int in[MAX];
    memcpy(in,ru,sizeof(ru));
    int x=0;
    priority_queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            {
                q.push(-i);
            }
    }
    while(!q.empty())
    {
        int t=-q.top();
        q.pop();
        ans[x]=t;
        x++;
        for(int i=1;i<=n;i++)
        {
            if(d[t][i])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(-i);
            }
        }
    }
    for(int i=0;i<x-1;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[x-1]<<endl;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
        memset(ans,0,sizeof(ans));
        memset(d,0,sizeof(d));
        memset(ru,0,sizeof(ru));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
        if(!d[x][y])
        {
            d[x][y]=1;
            ru[y]++;
        }
        }
      topsort();
        }
 
}
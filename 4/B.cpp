#include<iostream>
#include<string.h>
using namespace std;
 
int num[100000];
int vis[100000];
int n;
int prim(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
 } 
  
  
 void dfs(int c)
 {
        if(c==n&&prim(num[n-1]+1))
    {
        printf("1");
        for(int i=1;i<n;i++)
        printf(" %d",num[i]);
        printf("\n");
    }
    if(c==n) return ;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&prim(num[c-1]+i))
        {
            num[c]=i;
            vis[i]=1;
            dfs(c+1);
            vis[i]=0;
        }
    }
     
 }
 int main()
{
    int k=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        num[0]=1;
        vis[1]=1;
        printf("Case %d:\n",k++);
        dfs(1);
        printf("\n");
    }
    return 0;
}
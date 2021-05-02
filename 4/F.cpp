#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
  
const int N = 200100;
int n, k;
struct node
{
    int x, step;
};
queue<node> Q;
int vis[N];
  
void BFS()
{
    int X, STEP;
    while(!Q.empty())
    {
        node w2= Q.front();
        Q.pop();
        X = w2.x;
        STEP = w2.step;
        if(X == k)
        {
            printf("%d\n",STEP);
            return ;
        }
        if(X >= 1 && vis[X - 1]==0)
        {
            node w3;
            vis[X - 1] = 1;
            w3.x = X - 1;
            w3.step = STEP + 1;
            Q.push(w3);
        }
        if(X <= k && vis[X + 1]==0)
        {
            node w3;
            vis[X + 1] = 1;
            w3.x = X + 1;
            w3.step = STEP + 1;
            Q.push(w3);
        }
        if(X <= k && vis[X * 2]==0)
        {
            node w3;
            vis[X * 2] = 1;
            w3.x = 2 * X;
            w3.step = STEP + 1;
            Q.push(w3);
        }
    }
}
  
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        while(!Q.empty())
            Q.pop();
        memset(vis,0,sizeof(vis));
        vis[n] = 1;
        node w1;
        w1.x = n;
        w1.step = 0;
        Q.push(w1);
        BFS();
    }
    return 0;
}
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
struct node {
    int x;
    int y;
    int step;
};
int m,n,x,y;
int map[401][401];
int X[8] = { 1,-1,2,-2,2,-2,1,-1 };   
int Y[8] = { 2,2,1,1,-1,-1,-2,-2 };
 
bool judge(int x,int y)
{
    if(x<1||y<1||x>n||y>m)
    {
        return false;
    }
    else if (map[x][y]!=-1)
    {
        return false;
    }
    else return true;
}
 
void BFS()
{
    queue <node> q;
    node t1 = {x,y,0}; 
    q.push(t1);
    map[x][y]=0;
    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(judge(t1.x+X[i],t1.y+Y[i]))
            {
                node t2 ={t1.x+X[i],t1.y+Y[i],t1.step+1};
                q.push(t2);
                map[t2.x][t2.y] = t2.step;
            }
        }
    }
}
 
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<map[i][j];
     
            cout<<" ";
             
        }
        cout<<endl;
    }
 } 
int main()
{
    memset(map,-1,sizeof(map));
    cin>>n>>m>>x>>y;
    BFS();
    print();
    return 0;
     
 }
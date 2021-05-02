#include <iostream>
using namespace std;
int X[4]={0,-1,0,1};
int Y[4]={-1,0,1,0};
char map[401][401]={'0'};
int m,n;
void DFS(int x,int y)
{
    int xx,yy;
    map[x][y]='0';
    for(int i=0;i<4;i++)
    {
        xx=x+X[i];
        yy=y+Y[i];
        if(xx<n&&xx>=0&&yy<m&&yy>=0)
        {
            if(map[xx][yy]!='0')
                DFS(xx,yy);
                map[xx][yy]='0';
        }
    }
}
int main()
{
 
    int sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>map[i];
    }
    /* 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<map[i][j];
     
            cout<<" ";
             
        }
        cout<<endl;
    }
     
    */
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]!='0')
            {
                sum++;
            //  cout<<sum<<"  "<<i<<"  "<<j<<endl;
                DFS(i,j);
            }
     
        }
    }
    cout<<sum<<endl;;
  
    return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;
char map[110][110];
int n,m,ans,vis[110][110];
void dfs(int i,int j){
    if(i<1||j<1||i>n||j>m) return ;
    if(vis[i][j]) return ;
    if(!vis[i][j]){
        vis[i][j]=1;
        if(map[i][j]=='#'){
            int f1=0,f2=0,f3=0,f4=0;
            if((map[i+1][j]=='#'&&!vis[i+1][j])||map[i+1][j]!='#') f1=1;
            if((map[i-1][j]=='#'&&!vis[i-1][j])||map[i-1][j]!='#') f2=1;
            if((map[i][j+1]=='#'&&!vis[i][j+1])||map[i][j+1]!='#') f3=1;
            if((map[i][j-1]=='#'&&!vis[i][j-1])||map[i][j-1]!='#') f4=1;
            if(f1&&f2&&f3&&f4) ans++;
        }
    }
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>map[i][j];
    dfs(1,1);
    if(ans) printf("There are %d ships.\n",ans);
    else printf("Bad placement.\n");
    return 0;
}

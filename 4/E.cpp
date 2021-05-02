#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
struct node{
    int x, y;
};
 
 
int arr[5][5];
bool vis[5][5];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
node pre[10][10];
 
 
void print(){
    stack<node> zhan;
    node lrh{4, 4};
 
    while(1){
        zhan.push(lrh);
        if(lrh.x==0 && lrh.y==0) break;
        lrh = pre[lrh.x][lrh.y];
    }
 
    while(!zhan.empty()){
        cout<<"("<<zhan.top().x<<", "<<zhan.top().y<<")"<<endl;
        zhan.pop();
    }
}
 
void bfs(int x, int y){
    queue<node> q;
    q.push(node{x, y});
    vis[x][y] = true;
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(tmp.x==4&&tmp.y==4) { print(); return;}
        for(int i=0; i<4; i++){
            int now_x = tmp.x + dx[i];
            int now_y = tmp.y + dy[i];
            if(0<=now_x && now_x<5 && 0<=now_y && now_y<5 && !vis[now_x][now_y] && arr[now_x][now_y]==0){
                q.push(node{now_x, now_y});
                pre[now_x][now_y] = tmp;
                vis[now_x][now_y] = true;
            }
        }
    }
}
 
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>arr[i][j];
 
    memset(vis, false, sizeof(vis));
    memset(pre, 0, sizeof(pre));
 
    bfs(0, 0);
 
    return 0;
}
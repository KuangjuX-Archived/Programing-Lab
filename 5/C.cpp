#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct node
{
    int x, y;
}f[10000100];  //这里写成1e7，因为下面的bfs是加入队列后再判断是否重复，1e6 RE了一发；
int n;
int ans[1010][1010];
char map[1010][1010];
int dir[4][2] = { 0, -1, 1, 0, -1, 0, 0, 1 };
void bfs(int x, int y){
    int sum = 0, t = 0;
    queue<node>q;
    q.push({ x, y });
    while (!q.empty()){
        int x = q.front().x, y = q.front().y;
        q.pop();
        if (ans[x][y])continue;
        ans[x][y] = 1;
        sum++;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (map[x][y] != map[xx][yy] && xx <= n&&xx >= 1 && yy <= n&&yy >= 1)
                q.push({ xx, yy }), f[t].x = xx, f[t++].y = yy;
        }
    }
    for (int i = 0; i < t; i++)    //从该点开始能走的点都变成该联通区域的点数
        ans[f[i].x][f[i].y] = sum;
}
int main(){
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%s", map[i] + 1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (ans[x][y] != 0)cout << ans[x][y] << endl;//如果该点走过了，输出答案即可
        else{                             //若该点未走过，从该点开始搜索；
            bfs(x, y);
            cout << ans[x][y] << endl;
        }
    }
    return 0;
}
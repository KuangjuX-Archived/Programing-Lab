#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int sticks[20];  //木棍数组
int side;        //正方形边长
int m;           //木棍个数
bool visited[20];
bool DFS(int sum, int number, int position){
    if(number == 3){       //能凑出三根就一定能围成正方形（剩下的一定能组合成一条边）
        return true;
    }
    for(int i = position; i < m; i ++){     //一共有n！条路线
        if(visited[i] || sum + sticks[i] > side){
            continue;
        }
        visited[i] = true;
        if(sum + sticks[i] == side){
            if(DFS(0, number + 1, 0)){   
                return true;
            }
        }else{    
            if(DFS(sum + sticks[i], number, i + 1)){   
                return true;
            }
        }
        visited[i] = false;   
    }
    return false;
}
bool Compare(int x, int y){
    return x > y;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        while(n --){
            scanf("%d", &m);
            int len = 0;
            for(int i = 0; i < m; i ++){
                scanf("%d", &sticks[i]);
                len += sticks[i];
            }
            memset(visited, false, sizeof(visited));  
            sort(sticks, sticks + m, Compare);   
            if(len % 4 != 0){    
                cout << "no" << endl;
                continue;
            }else{
                side = len / 4;
                if(sticks[0] > side){   
                    cout << "no" << endl;
                    continue;
                }
            }
            if(DFS(0, 0, 0)){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
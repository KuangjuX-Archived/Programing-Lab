#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 10002
using namespace std;
  
struct coor{
    int x;
    int y;
    int value;
}q[N * 2];
int n, m, cnt, sum, far[N];
  
int get(int x){
    return x != far[x]?far[x] = get(far[x]):x;
}
bool cmp(const coor &a, const coor &b){
    return a.value > b.value;
}
  
int main(){
    while (~scanf("%d%d", &n, &m)){
        memset(q, 0, sizeof(q));
        cnt = sum = 0;
        for (int i = 1; i <= n; i++)
            far[i] = i;
         
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].value);
  
        sort(q, q + m, cmp);
  
        for (int i = 0; i < m; i++)
            if (get(q[i].x) != get(q[i].y)){
                sum += q[i].value;
                cnt++;
                far[get(q[i].x)] = get(q[i].y);
            }
  
        if (cnt == n - 1)
            printf("%d\n", sum);
        else
            printf("-1\n");
    }
    return 0;}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxN = 5e4 + 7;
char s1[maxN], s2[maxN];
int nex[maxN], pre[maxN];
void cal_nex(int len)
{
    nex[0] = nex[1] = 0;
    int k = 0;
    for(int i=2; i<=len; i++)
    {
        while(k > 0 && s1[k+1] != s1[i]) k = nex[k];
        if(s1[k+1] == s1[i]) k++;
        nex[i] = k;
    }
}
int solve(int len)
{
    int k = 0;
    for(int i=1; i<=len; i++)
    {
        while(k > 0 && s1[k+1] != s2[i]) k = nex[k];
        if(s1[k+1] == s2[i]) k++;
        if(i == len) return k;
    }
    return 0;
}
int main()
{
    while(scanf("%s%s", s1 + 1, s2 + 1)!=EOF)
    {
        int len = (int)strlen(s1 + 1);
        cal_nex(len);
        int ans = solve((int)strlen(s2 + 1));
        if(ans == 0) { printf("0\n");   continue; }
        for(int i=1; i<=ans; i++) printf("%c", s1[i]);
        printf(" %d\n", ans);
    }
    return 0;
}
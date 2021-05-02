#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;
//LOOP
#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
//OTHER
#define PB push_back
//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RS(s) scanf("%s", s)
//OUTPUT

#define sqr(x) (x) * (x)
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const double eps = 1e-9;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 100010;

map<int, int>col, row;
map<pair<int, int>, int>maze;
int main()
{
    //freopen("0.txt", "r", stdin);
    int T, n, m, k, a, t;
    RI(T);
    FE(kase, 1, T)
    {
        row.clear(), col.clear(), maze.clear();
        printf("Case #%d:\n", kase);
        RIII(n, m, k);
        int x, y, c, Q;
        REP(i, k)
        {
            RIII(x, y, c);
            maze[make_pair(x, y)] = c;
        }
        int tx, ty;
        RI(Q);
        while (Q--)
        {
            RIII(c, x, y);
            tx = x, ty = y;
            if (c == 2)
            {
                if (col.count(x))   tx = col[x];
                if (col.count(y))   ty = col[y];
                col[x] = ty;
                col[y] = tx;
            }
            else if (c == 1)
            {
                if (row.count(x))   tx = row[x];
                if (row.count(y))   ty = row[y];
                row[x] = ty;
                row[y] = tx;
            }
            else
            {
                if (row.count(x))
                    x = row[x];
                if (col.count(y))
                    y = col[y];
                a = 0;
                if (maze.count(make_pair(x, y)))
                    a = maze[make_pair(x, y)];
                printf("%d\n", a);
            }
        }
    }
    return 0;
}
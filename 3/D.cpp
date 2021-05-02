#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
//#include <bits/stdc++.h>
//#define LOACL
#define space " "
using namespace std;
typedef long long LL;
//typedef __int64 Int;
typedef pair<int, int> paii;
const int INF = 0x3f3f3f3f;
const double ESP = 1e-5;
const double Pi = acos(-1.0);
const int MOD = 1e9+5;
const int MAXN = 1e6 + 5;
int  main() {
    int k, n, t;
    int Kcase = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k)%i;
        }
        printf("Case %d: %d\n", ++Kcase, ans + 1);
    }
    return 0;
}
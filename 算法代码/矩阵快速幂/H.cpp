#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<set>
#include<utility>
#include<map>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926535898;
const LL mod=1e9+7;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//------------------------------------------
const int N = 90;
const int M = 50;

struct mat {
    LL a[N][N];
    mat() { memset(a, 0, sizeof(a)); }
};

int n, k;
LL s, c[M][M];

void init () {
    cin >> s >> k;
    n = k * 2 + 3;
    for (int i = 0; i <= k; i++) {
        c[i][0] = c[i][i] = 1;;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
}

mat mul(mat p, mat q) {
    mat ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            for (int t = 0; t < n; t++) {
                ans.a[i][j] += p.a[i][t]*q.a[t][j];
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

mat mat_pow(mat base, LL t) {
    mat x;
    for (int i = 0; i < n; i++) x.a[i][i] = 1;

    while (t) {
        if (t&1) x = mul(x, base);
        base = mul(base, base);
        t /= 2;
    }
    return x;
}

int main () {
    init();
    mat base;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            base.a[i][j] = base.a[i+k+1][j] = base.a[i][j+k+1] = c[i][j];
        }
    }
    base.a[2*k+2][k] = base.a[2*k+2][2*k+2] = 1;
    mat ans = mat_pow(base, s);
    LL res;
    for (int i = 0; i < 2*k+2; i++) {
        res= (res+ ans.a[2*k+2][i]) % mod;
    }
    cout <<res<< endl;
    return 0;
}

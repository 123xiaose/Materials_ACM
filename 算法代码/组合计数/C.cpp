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
#include<map>
#include<utility>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926;
const int mod=1e9+7;
const int maxn=105;
const int maxm=1005;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

LL qpow(LL x,LL y)
{
    LL res=1;
    while(y)
    {
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y=y>>1;
    }
    return res%mod;
}

LL n;

int main()
{
    int T,kase=0;
    while(~scanf("%d",&T))
    {
        kase=0;
        while(T--)
        {
            scanf("%lld",&n);
            LL x=2;
            LL ans=n*qpow(x,n-1)%mod;
            printf("Case #%d: %lld\n",++kase,ans);
        }
    }
    return 0;
}

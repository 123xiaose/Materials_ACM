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
const LL mod=1e9+7;
const int maxn=1e6+5;
const int maxm=1111;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

LL C[maxn],Cat[maxn],inv[maxn];

void init()
{
    C[0]=1;
    inv[1]=1;
    for(int i=2;i<maxn;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    Cat[0]=Cat[1]=1;
    for(int i=2;i<maxn;i++)
    {
        Cat[i]=Cat[i-1]*(4*i-2)%mod*inv[i+1]%mod;
    }
}

int main()
{
    int T,n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)C[i]=C[i-1]*(n-i+1)%mod*inv[i]%mod;
        LL res=0;
        for(int i=0;i<=n/2;i++)
            res+=(Cat[i]*C[i*2])%mod;
        printf("%lld\n",res%mod);
    }
    return 0;
}

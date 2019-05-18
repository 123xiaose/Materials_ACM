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
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

ll str[maxn],n,m,L,temp[maxn];

bool check(ll x)
{
    ll cnt=0,i;
    for(i=0;i<=n+1;i++)temp[i]=str[i];
    for(i=1;i<=n;i++)
    {
        if(temp[i]-temp[i-1]<x)
        {
            temp[i]=temp[i-1];
            cnt++;
        }
    }
    if(temp[n+1]-temp[n]<x)cnt++;
    //printf("cnt=%d\n",cnt);
    return cnt<=m;
}

void solve()
{
    ll lb=0,ub=INF;
    while(ub-lb>1)
    {
        ll mid=(lb+ub)/2;
        if(check(mid))lb=mid;
        else
            ub=mid;
        //printf("%lld %lld\n",lb,ub);
    }
    //printf("%lld %lld\n",lb,ub);
    printf("%lld\n",lb);
}

int main()
{
    while(~scanf("%lld%lld%lld",&L,&n,&m))
    {
        for(ll i=1;i<=n;i++)
        {
            scanf("%d",&str[i]);
        }
        sort(str+1,str+1+n);
        str[0]=0;str[n+1]=L;
        //for(int i=0;i<=n+1;i++)printf("%d ",str[i]);
        //printf("\n");
        solve();
    }
    return 0;
}

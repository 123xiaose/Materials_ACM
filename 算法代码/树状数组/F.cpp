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
const int mod=1e9+7;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-----------------------------------

LL c1[maxn],c2[maxn],sum[maxn],x,y,d,n,q;

LL lowbit(LL k)
{
    return k&(-k);
}

void update(LL i,LL v,LL *c)
{
    while(i<=n)
    {
        c[i]+=v;
        i+=lowbit(i);
    }
}

LL query(LL i,LL *c)
{
    LL s=0;
    for(;i>0;s+=c[i],i-=lowbit(i));
    return s;
}

int main()
{
    while(~scanf("%lld",&n))
    {
        if(n==0)break;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            update(x,1,c1);
            update(y+1,-1,c1);
            update(x,x,c2);
            update(y+1,-(y+1),c2);
        }
        for(int i=1;i<n;i++)
        {
             printf("%lld ",query(i,c1)*(i+1)-query(i,c2)-query(i-1,c1)*i+query(i-1,c2));
        }
        printf("%lld\n",query(n,c1)*(n+1)-query(n,c2)-query(n-1,c1)*n+query(n-1,c2));
    }
    return 0;
}

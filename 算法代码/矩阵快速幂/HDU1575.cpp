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
const int mod=9973;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-------------------------------------------
int T,n,k;

struct mat
{
    LL str[10][10];
};

mat c;

mat mat_mul(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                result.str[i][j]+=(x.str[i][k]*y.str[k][j])%mod;
            }
        }
    }
    return result;
}

void mat_pow(int x)
{
    mat res;LL ans=0;
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<n;i++)res.str[i][i]=1;
    while(x)
    {
        if(x%2==1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        x=x>>1;
    }
    for(int i=0;i<n;i++)
    {
        ans+=res.str[i][i]%mod;
    }
    printf("%lld\n",ans%mod);
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&n,&k);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)scanf("%lld",&c.str[i][j]);
            }
            mat_pow(k);
        }
    }
    return 0;
}

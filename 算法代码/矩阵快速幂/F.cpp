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
//-------------------------------------------
LL n,k,a,b;
struct mat
{
    LL str[2][2];
};

mat mat_mul(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                result.str[i][j]+=(x.str[i][k]*y.str[k][j])%(mod-1);
                result.str[i][j]=result.str[i][j]%(mod-1);
            }
        }
    }
    return result;
}

mat mat_pow(LL k)
{
    mat res,c,tmp;
    for(int i=0;i<2;i++)c.str[0][i]=1;
    c.str[1][0]=1;c.str[1][1]=0;
    memset(res.str,0,sizeof(res.str));
    memset(tmp.str,0,sizeof(tmp.str));
    for(int i=0;i<2;i++)tmp.str[i][0]=1;
    for(int i=0;i<2;i++)res.str[i][i]=1;
    while(k)
    {
        if(k&1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        k=k>>1;
    }
    res=mat_mul(res,tmp);
    return res;
}

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

int main()
{
    while(~scanf("%lld%lld%lld",&a,&b,&n))
    {
        mat ans;
        if(n==0)printf("%lld\n",a);
        else if(n==1)printf("%lld\n",b);
        else
        {
            ans=mat_pow(n-2);
            printf("%lld\n",qpow(a, ans.str[1][0])*qpow(b, ans.str[0][0])%mod);
        }
    }
    return 0;
}

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
LL n,k,a,b,a0,b0,ax,bx,ay,by;
struct mat
{
    LL str[5][5];
};

mat mat_mul(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                result.str[i][j]+=(x.str[i][k]*y.str[k][j])%mod;
                result.str[i][j]=result.str[i][j]%mod;
            }
        }
    }
    return result;
}

mat mat_pow(LL k)
{
    mat res,tmp,c;
    memset(res.str,0,sizeof(res.str));
    memset(tmp.str,0,sizeof(tmp.str));
    memset(c.str,0,sizeof(c.str));
    for(int i=0;i<5;i++)res.str[i][i]=1;
    tmp.str[0][0]=a0*b0%mod;tmp.str[1][0]=a0*b0%mod;tmp.str[2][0]=a0%mod;
    tmp.str[3][0]=b0%mod;tmp.str[4][0]=1;

    c.str[0][0]=1;c.str[0][1]=ax*bx%mod;c.str[0][2]=ax*by%mod;c.str[0][3]=bx*ay%mod;c.str[0][4]=ay*by%mod;
    c.str[1][0]=0;c.str[1][1]=ax*bx%mod;c.str[1][2]=ax*by%mod;c.str[1][3]=bx*ay%mod;c.str[1][4]=ay*by%mod;
    c.str[2][0]=0;c.str[2][1]=0;c.str[2][2]=ax%mod;c.str[2][3]=0;c.str[2][4]=ay%mod;
    c.str[3][0]=0;c.str[3][1]=0;c.str[3][2]=0;c.str[3][3]=bx%mod;c.str[3][4]=by%mod;
    c.str[4][0]=0;c.str[4][1]=0;c.str[4][2]=0;c.str[4][3]=0;c.str[4][4]=1;
    while(k)
    {
        if(k&1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        k=k>>1;
    }
    res=mat_mul(res,tmp);
    return res;
}

int main()
{
    while(~scanf("%lld",&n))
    {
        scanf("%lld%lld%lld",&a0,&ax,&ay);
        scanf("%lld%lld%lld",&b0,&bx,&by);
        if(n==0)printf("0\n");
        else
        {
            mat ans=mat_pow(n-1);
            printf("%lld\n",ans.str[0][0]%mod);
        }
    }
    return 0;
}

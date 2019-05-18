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
//const int mod=1000;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-------------------------------------------
int n,k,mod;
struct mat
{
    LL str[32][32];
};

mat A;
mat mat_sum(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)result.str[i][j]=(x.str[i][j]+y.str[i][j])%mod;
    }
    return result;
}

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

mat mat_pow(int k)
{
    mat res,c;
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<n;i++)res.str[i][i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)c.str[i][j]=A.str[i][j];
    }
    while(k)
    {
        if(k&1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        k=k>>1;
    }
    return res;
}

mat mat_solve(int k)
{
    if(k==1)return A;
    mat tmp,tnow;
    tmp=mat_solve(k/2);
    if(k&1)
    {
        tnow=mat_pow(k/2+1);
        tmp=mat_sum(tmp,mat_mul(tmp,tnow));
        tmp=mat_sum(tnow,tmp);
    }
    else
    {
        tnow=mat_pow(k/2);
        tmp=mat_sum(tmp,mat_mul(tmp,tnow));
    }
    return tmp;
}

int main()
{
    while(~scanf("%d%d%d",&n,&k,&mod))
    {
        memset(A.str,0,sizeof(A.str));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%lld",&A.str[i][j]);
                A.str[i][j]=A.str[i][j]%mod;
            }
        }
        mat ans=mat_solve(k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)printf("%lld ",ans.str[i][j]);
            printf("\n");
        }
    }
    return 0;
}

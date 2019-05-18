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
const LL mod=2147493647;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-------------------------------------------
LL n,k,x,y,z,m,T;

struct mat
{
    LL str[10][10];
};

mat mat_mul(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            for(int k=0;k<7;k++)
            {
                result.str[i][j]=(result.str[i][j]+x.str[i][k]*y.str[k][j]%mod)%mod;
            }
        }
    }
    return result;
}

void mat_pow(LL x,LL y,LL k)
{
    mat res,c;
    c.str[0][0]=1;c.str[0][1]=2;c.str[0][2]=1;c.str[0][3]=4;c.str[0][4]=6;c.str[0][5]=4;c.str[0][6]=1;
    c.str[1][0]=1;c.str[1][1]=0;c.str[1][2]=0;c.str[1][3]=0;c.str[1][4]=0;c.str[1][5]=0;c.str[1][6]=0;
    c.str[2][0]=0;c.str[2][1]=0;c.str[2][2]=1;c.str[2][3]=4;c.str[2][4]=6;c.str[2][5]=4;c.str[2][6]=1;
    c.str[3][0]=0;c.str[3][1]=0;c.str[3][2]=0;c.str[3][3]=1;c.str[3][4]=3;c.str[3][5]=3;c.str[3][6]=1;
    c.str[4][0]=0;c.str[4][1]=0;c.str[4][2]=0;c.str[4][3]=0;c.str[4][4]=1;c.str[4][5]=2;c.str[4][6]=1;
    c.str[5][0]=0;c.str[5][1]=0;c.str[5][2]=0;c.str[5][3]=0;c.str[5][4]=0;c.str[5][5]=1;c.str[5][6]=1;
    c.str[6][0]=0;c.str[6][1]=0;c.str[6][2]=0;c.str[6][3]=0;c.str[6][4]=0;c.str[6][5]=0;c.str[6][6]=1;
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<7;i++)res.str[i][i]=1;
    while(k)
    {
        if(k%2==1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        k=k>>1;
    }
    mat tmp;
    memset(tmp.str,0,sizeof(tmp.str));
    tmp.str[0][0]=y;tmp.str[1][0]=x;tmp.str[2][0]=16;tmp.str[3][0]=8;
    tmp.str[4][0]=4;tmp.str[5][0]=2;tmp.str[6][0]=1;
    res=mat_mul(res,tmp);
    printf("%lld\n",(res.str[0][0]+mod)%mod);
}

int main()
{
    while(~scanf("%lld",&T))
    {
        while(T--)
        {
            scanf("%lld %lld %lld",&k,&x,&y);
            if(k==1)printf("%lld\n",x);
            else if(k==2)printf("%lld\n",y);
            else
            {
                mat_pow(x,y,k-2);
            }
        }
    }
    return 0;
}

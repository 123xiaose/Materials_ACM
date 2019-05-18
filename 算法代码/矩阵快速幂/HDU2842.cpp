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
const int mod=200907;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-------------------------------------------
int T,n,k;

struct mat
{
    LL str[3][3];
};

mat mat_mul(mat x,mat y)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                result.str[i][j]+=(x.str[i][k]*y.str[k][j])%mod;
            }
        }
    }
    return result;
}

void mat_pow(int x)
{
    mat res,c;
    c.str[0][0]=1;c.str[0][1]=2;c.str[0][2]=1;
    c.str[1][0]=1;c.str[1][1]=0;c.str[1][2]=0;
    c.str[2][0]=0;c.str[2][1]=0;c.str[2][2]=1;
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<3;i++)res.str[i][i]=1;
    while(x)
    {
        if(x%2==1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        x=x>>1;
    }
    mat tmp;
    memset(tmp.str,0,sizeof(tmp.str));
    tmp.str[0][0]=2;tmp.str[1][0]=1;tmp.str[2][0]=1;
    res=mat_mul(res,tmp);
    printf("%lld\n",res.str[0][0]%mod);
}

int main()
{
    while(~scanf("%d",&k))
    {
        if(k==0)break;
        if(k==1)printf("%d\n",1);
        else if(k==2)printf("%d\n",2);
        else
            mat_pow(k-2);
    }
    return 0;
}

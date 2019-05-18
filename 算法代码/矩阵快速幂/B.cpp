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
const int mod=1000;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-------------------------------------------
int T,n,k,x,y,z,m;

struct mat
{
    LL str[20][20];
};

mat tmp;

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

void mat_pow(int x,int y,int z)
{
    mat res,c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c.str[i][j]=tmp.str[i][j];
        }
    }
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<n;i++)res.str[i][i]=1;
    while(z)
    {
        if(z%2==1)res=mat_mul(res,c);
        c=mat_mul(c,c);
        z=z>>1;
    }
    printf("%lld\n",res.str[x][y]%mod);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)break;
        memset(tmp.str,0,sizeof(tmp.str));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            tmp.str[x][y]=1;
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            mat_pow(x,y,z);
        }
    }
    return 0;
}

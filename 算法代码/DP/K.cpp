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
const double Pi=3.1415926;
const int mod=1e9+7;
const int maxn=1000+5;
const int INF=1e18;
using namespace std;

//-----------------------------------
struct Block
{
    int l,w,h;
}block[200];

int T,N,dp[200],x,y,z,n;

bool cmp(Block a,Block b)
{
    if(a.l==b.l)
        return a.w<b.w;
    else
        return a.l<b.l;
}

int main()
{
    int k=0;
    while(~scanf("%d",&N))
    {
        if(N==0)break;
        n=6*N;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;)
        {
            scanf("%d%d%d",&x,&y,&z);
            block[i].l = x; block[i].w = y; block[i].h = z; i++;
            block[i].l = x; block[i].w = z; block[i].h = y; i++;
            block[i].l = y; block[i].w = x; block[i].h = z; i++;
            block[i].l = y; block[i].w = z; block[i].h = x; i++;
            block[i].l = z; block[i].w = x; block[i].h = y; i++;
            block[i].l = z; block[i].w = y; block[i].h = x; i++;
        }
        sort(block,block+n,cmp);
        //for(int i=0;i<n;i++)printf("%d %d %d\n",block[i].l,block[i].w,block[i].h);
        for(int i=0;i<n;i++)
        {
            dp[i]=block[i].h;
            for(int j=0;j<i;j++)
            {
                if( (block[j].l<block[i].l)&&(block[j].w<block[i].w) )
                {
                    dp[i]=max(dp[i],dp[j]+block[i].h);
                }
            }
        }
        //for(int i=0;i<n;i++)printf("%d\n",dp[i]);
        sort(dp,dp+n);
        printf("Case %d: maximum height = %d\n",++k,dp[n-1]);
    }
    return 0;
}

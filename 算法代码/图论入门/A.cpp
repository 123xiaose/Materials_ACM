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
const int maxn=105;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

int d[maxn][maxn],dp[10005],cost[maxn],w[maxn];
int T,n,m,sum,s;

void floyd(int n)
{
    for(int k=0;k<=n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

void DP(int s,int n)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=cost[i];j--)
        {
            dp[j]=max(dp[j],dp[j-cost[i]]+w[i]);
        }
    }
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&n,&m);
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    d[i][j]=INF;
                }
            }
            for(int i=0;i<m;i++)
            {
                int s,t,v;
                scanf("%d%d%d",&s,&t,&v);
                if(d[s][t]>v)
                {
                    d[s][t]=v;d[t][s]=v;
                }
            }
            sum=0;s=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&w[i]);
                sum+=w[i];
            }
            //sum=(sum+1)/2;
            sum=(sum>>1)+1;
            //sum=(sum/2)+1;
            floyd(n);
            for(int i=1;i<=n;i++)
            {
                cost[i]=d[0][i];
                if(cost[i]!=INF)
                {
                    s+=cost[i];
                }
            }
            DP(s,n);
            int flag=0;
            for(int i=1;i<=s;i++)
            {
                if(dp[i]>=sum)
                {
                    flag=1;
                    printf("%d\n",i);
                    break;
                }
            }
            if(!flag)
            {
                printf("impossible\n");
            }
        }
    }
    return 0;
}

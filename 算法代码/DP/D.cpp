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
int n,m,k,s;
int v[105],w[105],dp[105][105];

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&v[i],&w[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<k;i++)
        {
            for(int j=w[i];j<=m;j++)
            {
                for(int t=1;t<=s;t++)
                {
                    dp[j][t]=max(dp[j][t],dp[j-w[i]][t-1]+v[i]);
                }
            }
        }
        if(dp[m][s]>=n)
        {
            for(int i=0;i<=m;i++)
            {
                if(dp[i][s]>=n)
                {
                    printf("%d\n",m-i);
                    break;
                }
            }
        }
        else
            printf("-1\n");
    }
	return 0;
}

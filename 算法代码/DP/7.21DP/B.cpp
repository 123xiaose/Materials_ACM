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
const int maxn=100000+5;
const int INF=1e18;

using namespace std;

//-----------------------------
int dp[maxn][15],N,i,j,t,x,T,ans;

int main()
{
    while(~scanf("%d",&N))
    {
        if(N==0)break;ans=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<N;i++)
        {
            scanf("%d%d",&x,&t);
            dp[t][x]++;
            T=max(T,t);
        }
        for(i=T-1;i>=0;i--)
        {
            for(j=0;j<=10;j++)
            {
                if(j==0)
                {
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
                }
                else if(j==10)
                {
                    dp[i][j]=max(dp[i+1][j-1],dp[i+1][j])+dp[i][j];
                }
                else
                    dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+dp[i][j];
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}

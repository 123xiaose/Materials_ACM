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
const int maxn=1e6+5;
const int INF=1e7;

using namespace std;

//-----------------------------
int str[maxn],dp[maxn];

int main()
{
    int N,ans,x,y,cnt,kase=0;
    while(~scanf("%d",&kase))
    {
        for(int i=1;i<=kase;i++)
        {
            x=1;y=1;
            scanf("%d",&N);
            memset(dp,-INF,sizeof(dp));
            ans=-INF;
            for(int j=1;j<=N;j++)
            {
               scanf("%d",&str[j]);
            }
            dp[1]=str[1];
            ans=dp[1];
            for(int j=2;j<=N;j++)
            {
               dp[j]=max(dp[j-1]+str[j],str[j]);
               if(dp[j]>ans)
               {
                 ans=dp[j];
                 y=j;
               }
            }
            int s=0;
            for(int j=y;j>=1;j--)
            {
              s+=str[j];
              if(s==ans)
                  {x=j;break;}
            }
            printf("Case %d:\n",i);
            printf("%d %d %d\n",ans,x,y);
            if(i!=kase)printf("\n");
        }
    }
    return 0;
}

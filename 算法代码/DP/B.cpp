#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

//-----------------------------

int dp[1005][1005];
int main()
{
    int n,str[1005],i,j,w,w1;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&str[i]);
        }
        scanf("%d",&w);
        sort(str+1,str+n+1);
        if(w<5)
        {
            printf("%d\n",w);
            continue;
        }
        w1=w;
        w-=5;
        memset(dp,0,sizeof(dp));
        for(i=1;i<n;i++)
        {
              for(j=0;j<=w;j++)
              {
                  if(j-str[i]>=0)
                  {
                      dp[i][j]=max(dp[i-1][j],dp[i-1][j-str[i]]+str[i]);
                  }
                  else
                    dp[i][j]=dp[i-1][j];
              }
        }
        printf("%d\n",w1-dp[n-1][w]-str[n]);
    }
    return 0;
}

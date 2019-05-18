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

int A[105],C[105],dp[maxn],ans,n,m;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        memset(A,0,sizeof(A));
        memset(C,0,sizeof(C));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        for(int i=0;i<n;i++)scanf("%d",&C[i]);
        if(m<0)
        {
            printf("%d\n",0);
            continue;
        }
        dp[0]=0;ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[j]>=0)
                {
                    dp[j]=C[i];
                }
                else if(j<A[i]||dp[j-A[i]]<=0)
                {
                    dp[j]=-1;
                }
                else
                {
                    dp[j]=dp[j-A[i]]-1;
                }
            }
        }
        for(int j=0;j<=m;j++){if(dp[j]>=0)ans++;}
        printf("%d\n",ans-1);
    }
    return 0;
}

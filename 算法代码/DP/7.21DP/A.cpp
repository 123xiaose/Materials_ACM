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
const int maxn=110000;
const int INF=1e18;

using namespace std;

//-----------------------------

l N,sum,ans,cnt,i,j,v[maxn],dp[maxn],a,b;

int main()
{
    while(~scanf("%ld",&N))
    {
        if(N<0)break;
        int cnt2=1;
        sum=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++)
        {
            scanf("%ld%ld",&a,&b);
            sum+=a*b;
            for(j=1;j<=b;j++)
            {
                v[cnt2++]=a;
            }
        }
        for(i=1;i<cnt2;i++)
        {
            for(j=sum/2;j>=v[i];j--)
            {
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
            }
        }
        ans=max(sum-dp[sum/2],dp[sum/2]);
        printf("%ld %ld\n",ans,sum-ans);
    }
    return 0;
}

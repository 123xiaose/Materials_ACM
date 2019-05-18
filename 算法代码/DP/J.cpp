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
const int maxn=10000+5;
const int INF=1e7;

using namespace std;

//-----------------------------
int str[1005],dp[1005],N,res,sum,x,y;

int main()
{
    while(~scanf("%d",&N))
    {
        res=0;x=y=0;sum=0;
        if(N==0)break;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&str[i]);
        }
        for(int i=0;i<N;i++)
        {
            dp[i]=str[i];
            for(int j=0;j<i;j++)
            {
                if(str[j]<str[i])
                {
                    if( dp[j]+str[i]>dp[i] ){dp[i]=dp[j]+str[i];}
                }
            }
            if(dp[i]>res)
            {
                res=dp[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

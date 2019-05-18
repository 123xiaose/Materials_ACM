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
const int mod=10000;
const int maxn=100000+2;
const int INF=1e18;

using namespace std;

//-----------------------------

int dp[205][205],str[205][205],T,n,m;

int rec(int i,int j)
{
    int eg=str[i][j];
    int ans=0;
    if(dp[i][j]>0)return dp[i][j];
    if( (i==n)&&(j==m) )return 1;
    for(int k=i;k<=i+eg;k++)
    {
        for(int w=j;w<=j+eg;w++)
        {
            if( (k==i)&&(w==j) )continue;
            else if( (k+w-i-j)<=eg )
            {
              ans=(ans+rec(k,w))%mod;
            }
        }
    }
    ans=ans%mod;
    return dp[i][j]=ans;
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            memset(str,0,sizeof(str));
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    cin>>str[i][j];
                }
            }
            memset(dp,0,sizeof(dp));
            printf("%d\n",rec(1,1));
        }
    }
    return 0;
}

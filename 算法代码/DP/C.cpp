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

//-----------------------------

char s[maxn],t[maxn];
int dp[maxn][maxn];

int main()
{
    while(~scanf("%s%s",s,t))
    {
        int len1=strlen(s);
        int len2=strlen(t);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(s[i]==t[j])
                {
                    dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i][j+1],dp[i+1][j]));
                }
                else
                {
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}

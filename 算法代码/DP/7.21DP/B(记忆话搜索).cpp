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

int dp[maxn][15]={0},str[maxn][15],N,t,x,T;

int res(int i,int j)
{
    int ans=str[i][j];
    if(dp[i][j]>0)return dp[i][j];
    if(i>=T)return ans;
    else
    {
       if(j==0)ans+=max(res(i+1,j),res(i+1,j+1));
       else if(j==10)ans+=max(res(i+1,j-1),res(i+1,j));
       else
          ans+=max(res(i+1,j),max(res(i+1,j-1),res(i+1,j+1)));
       return dp[i][j]=ans;
    }
}

int main()
{
    while(~scanf("%d",&N))
    {
        if(N==0)break;
        memset(dp,0,sizeof(dp));
        memset(str,0,sizeof(str));
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&x,&t);
            str[t][x]++;
            T=max(T,t);
        }
       // printf("T=%d\n",T);
        printf("%d\n",res(0,5));
    }
    return 0;
}

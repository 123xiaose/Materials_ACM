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
const int INF=1e7;

using namespace std;

//-----------------------------
int m,n,temp[maxn],h[maxn];

char str[maxn][maxn];

int deal()
{
    int res=0;
    memcpy(temp,h,sizeof(h));
    sort(temp+1,temp+m+1);
    for(int i=m;i>=1;i--)
    {
        if(temp[i])
        {
            res=max(res,(m-i+1)*temp[i]);
        }
    }
    return res;
}
int dp()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='1'){h[j]++;}
            else
                h[j]=0;
        }
        ans=max(ans,deal());
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str[i]+1);
        }
        memset(temp,0,sizeof(temp));
        memset(h,0,sizeof(h));
        printf("%d\n",dp());
    }
    return 0;
}

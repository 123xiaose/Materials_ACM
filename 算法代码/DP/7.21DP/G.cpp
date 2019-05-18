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

char str[maxn][maxn];
int L[maxn],r[maxn],h[maxn][maxn];
int m,n,ans;

void dp()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            L[j]=j;r[j]=j;
        }
        h[i][0]=-1;h[i][n+1]=-1;
        for(int j=1;j<=n;j++)
        {
            while(h[i][L[j]-1]>=h[i][j])
            {
                L[j]=L[L[j]-1];
            }
        }
        for(int j=n;j>=1;j--)
        {
            while(h[i][r[j]+1]>=h[i][j])
            {
                r[j]=r[r[j]+1];
            }
        }
        for(int j=1;j<=n;j++)
        {
            ans=max(ans,(r[j]-L[j]+1)*h[i][j]);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        ans=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%s",str[i]+1);
        }
        memset(h,0,sizeof(h));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i][j]=='a' || str[i][j]=='w' || str[i][j]=='y' || str[i][j]=='z')
                {
                    h[i][j]=h[i-1][j]+1;
                }
            }
        }
        dp();
        memset(h,0,sizeof(h));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i][j]=='b' || str[i][j]=='w' || str[i][j]=='x' || str[i][j]=='z')
                {
                    h[i][j]=h[i-1][j]+1;
                }
            }
        }
        dp();
        memset(h,0,sizeof(h));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i][j]=='c' || str[i][j]=='x' || str[i][j]=='y' || str[i][j]=='z')
                {
                    h[i][j]=h[i-1][j]+1;
                }
            }
        }
        dp();
        //ans=max(ans1,max(ans2,ans3));
        printf("%d\n",ans);
    }
    return 0;
}

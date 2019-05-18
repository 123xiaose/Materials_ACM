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
int T,m,n,res;
int L[maxn],r[maxn],h[maxn][maxn];

char str[maxn][maxn];

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
            res=max(res,(r[j]-L[j]+1)*h[i][j]);
        }
    }
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&m,&n);
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    //getchar();
                    //scanf("%c",&str[i][j]);
                    cin>>str[i][j];
                }
            }
            memset(h,0,sizeof(h));
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(str[i][j]=='F')
                    {
                        h[i][j]=h[i-1][j]+1;
                    }
                }
            }
            res=0;
            dp();
            printf("%d\n",res*3);
        }
    }
    return 0;
}

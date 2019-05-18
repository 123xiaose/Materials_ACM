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
int N,str[maxn][maxn],ans[maxn][maxn],res;

int main()
{
    //In();Out();
    while(~scanf("%d",&N))
    {
        res=0;
        memset(str,0,sizeof(str));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&str[i][j]);
            }
        }
        ans[0][0]=str[0][0];
        for(int i=1;i<N;i++)
        {
            ans[i][0]=ans[i-1][0]+str[i][0];
            ans[i][i]=ans[i-1][i-1]+str[i][i];
        }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                ans[i][j]=str[i][j]+max(ans[i-1][j-1],ans[i-1][j]);
            }
        }
        for(int i=0;i<N;i++)
        {
            res=max(res,ans[N-1][i]);
        }
        printf("%d\n",res);
    }
    return 0;
}

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
#include<utility>
#include<map>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

char str[305][305];
int mmp[305][305],r,c,k;

void solve()
{
    for(int i=1;i<=r;i++)mmp[i][1]=(str[i][1]=='.');
    for(int i=1;i<=c;i++)mmp[1][i]=(str[1][i]=='.');
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            mmp[i][j]=(mmp[i-1][j]+mmp[i][j-1]-mmp[i-1][j-1]+(str[i][j]=='.'));
        }
    }
}

int check(int x1,int y1,int x2,int y2)
{
    if(mmp[x2][y2]+mmp[x1-1][y1-1]-mmp[x1-1][y2]-mmp[x2][y1-1]>=k)return 0;
    else
        return 1;
}

int main()
{
    while(~scanf("%d%d%d",&r,&c,&k))
    {
        if(r==0 && c==0 && k==0)break;
        memset(mmp,0,sizeof(mmp));
        for(int i=1;i<=r;i++)scanf("%s",str[i]+1);
        int res=INF;
        solve();
        for(int i=1;i<=r;i++)
        {
            for(int j=i;j<=r;j++)
            {
                for(int t1=1,t2=1;t1<=c;t1++)
                {
                    while(check(i,t1,j,t2)==1 && t2<c)t2++;
                    if(check(i,t1,j,t2)==0)res=min(res,(j-i+1)*(t2-t1+1));
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

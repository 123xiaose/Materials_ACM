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
const int maxn=3*1e7+5;
const int INF=0x3f3f3f3f;

using namespace std;

//-----------------------------------

int res[maxn];

void init()
{
    memset(res,0,sizeof(res));
    for(int c=1;c<=maxn/2;c++)
    {
        for(int a=c+c;a<=maxn;a+=c)
        {
            int b=a-c;
            if( (a^b)==c)res[a]++;
        }
    }
    for(int i=2;i<=maxn;i++)
    {
        res[i]+=res[i-1];
    }
}

int main()
{
    int T,kase=0,n;
    while(~scanf("%d",&T))
    {
        kase=0;init();
        while(T--)
        {
            scanf("%d",&n);
            printf("Case %d: %d\n",++kase,res[n]);
        }
    }
    return 0;
}

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
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=2*1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-----------------------------------

int s[maxn],c[maxn],a,b,T,n;

int lowbit(int k)
{
    return k&(-k);
}

void update(int i,int v)
{
    while(i<=n)
    {
        c[i]+=v;
        i+=lowbit(i);
    }
}
void init()
{
    for(int i=1;i<=n;i++)update(i,s[i]);
}

int sum(int i)
{
    int s=0;
    for(;i>0;s+=c[i],i-=lowbit(i));
    return s;
}

int main()
{
    while(~scanf("%d",&T))
    {
        int kase=0;
        while(T--)
        {
            scanf("%d",&n);
            for(int i=1;i<=n;i++)scanf("%d",&s[i]);
            memset(c,0,sizeof(c));
            init();
            printf("Case %d:\n",++kase);
            char str[10];
            while(~scanf("%s",str))
            {
                if(str[0]=='E')break;
                if(str[0]=='Q')
                {
                    scanf("%d%d",&a,&b);
                    printf("%d\n",sum(b)-sum(a-1));
                }
                else if(str[0]=='A')
                {
                    scanf("%d%d",&a,&b);
                    update(a,b);
                }
                else if(str[0]=='S')
                {
                    scanf("%d%d",&a,&b);
                    update(a,-b);
                }
            }
        }
    }
    return 0;
}

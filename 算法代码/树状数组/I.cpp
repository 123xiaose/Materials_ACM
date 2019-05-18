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
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-----------------------------------

struct Node
{
    int x,y;
}node[1005*1005];

int n,m,k,T;
LL c[maxn];

bool cmp(Node a,Node b)
{
    if(a.x==b.x)return a.y<b.y;
    else
        return a.x<b.x;
}

int lowbit(int k)
{
    return k&(-k);
}

void build(int pos,int val)
{
    for(int i=pos;i<=m;i+=lowbit(i))
    {
        c[i]+=val;
    }
}

LL getsum(int pos)
{
    LL res=0;
    for(int i=pos;i>0;i-=lowbit(i))
    {
        res+=c[i];
    }
    return res;
}

int main()
{
    while(~scanf("%d",&T))
    {
        int kase=0;
        while(T--)
        {
            scanf("%d%d%d",&n,&m,&k);
            for(int i=0;i<k;i++)scanf("%d%d",&node[i].x,&node[i].y);
            sort(node,node+k,cmp);
            memset(c,0,sizeof(c));
            LL ans=0;
            for(int i=0;i<k;i++)
            {
                build(node[i].y,1);
                ans+=getsum(m)-getsum(node[i].y);
            }
            printf("Test case %d: %lld\n",++kase,ans);
        }
    }
    return 0;
}

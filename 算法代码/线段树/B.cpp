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
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1

int val[maxn],pos[maxn],ans[maxn],n,k;
int tree[maxn<<2];

void build(int l,int r,int rt)
{
    int m=(l+r)>>1;
    tree[rt]=r-l+1;
    if(l==r)return;
    build(lson);
    build(rson);
}

void update(int p,int l,int r,int rt)
{
    int m=(l+r)>>1;
    tree[rt]--;
    if(l==r)
    {
        k=l;
        return;
    }
    if(p<=tree[rt*2])update(p,lson);
    else
    {
        p-=tree[rt*2];
        update(p,rson);
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        for(int i=1;i<=n;i++)scanf("%d%d",&pos[i],&val[i]);
        for(int i=n;i>=1;i--)
        {
            update(pos[i]+1,1,n,1);
            ans[k]=val[i];
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}

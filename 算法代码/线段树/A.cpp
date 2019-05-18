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
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-----------------------------------
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1

int n,h,w,tmp;

struct Node
{
    int l,r,M;
    int mid()
    {
        return (l+r)>>1;
    }
}tree[200000*4];

void build(int l,int r,int rt,int w)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].M=w;
    if(l==r)return;
    int m=tree[rt].mid();
    build(lson,w);
    build(rson,w);
}

void update(int tmp,int rt)
{
    if(tree[rt].l==tree[rt].r)
    {
        printf("%d\n",tree[rt].l);
        tree[rt].M-=tmp;
        return;
    }
    if(tmp<=tree[rt*2].M)update(tmp,rt*2);
    else
        update(tmp,rt*2+1);
    tree[rt].M=max(tree[rt*2].M,tree[rt*2+1].M);
}

int main()
{
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        if(h>n)h=n;
        build(1,h,1,w);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            if(tmp<=tree[1].M)update(tmp,1);
            else
                printf("-1\n");
        }
    }
    return 0;
}

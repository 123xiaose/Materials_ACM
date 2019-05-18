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

//-----------------------------------
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1

using namespace std;

LL sum[maxn<<2],add[maxn<<2];
int n,k,a,b,c;

struct Node
{
    int l,r;
    int mid()
    {
        return (l+r)>>1;
    }

}tree[maxn<<2];

void pushup(int rt)
{
    sum[rt]=sum[rt*2]+sum[rt*2+1];
}

void pushdown(int rt,int m)
{
    if(add[rt])
    {
        add[rt*2]+=add[rt];
        add[rt*2+1]+=add[rt];
        sum[rt*2]+=add[rt]*(m-(m/2));
        sum[rt*2+1]+=add[rt]*(m/2);
        add[rt]=0;
    }
}

void build(int l,int r,int rt)
{
    tree[rt].l=l;
    tree[rt].r=r;
    add[rt]=0;
    if(l==r){scanf("%lld",&sum[rt]);return;}
    int m=tree[rt].mid();
    build(lson);
    build(rson);
    pushup(rt);
}


void update(int c,int l,int r,int rt)
{
    if(tree[rt].l==l && tree[rt].r==r)
    {
        add[rt]+=c;
        sum[rt]+=(LL)c*(r-l+1);
        return;
    }
    if(tree[rt].l==tree[rt].r)return;
    pushdown(rt,tree[rt].r-tree[rt].l+1);
    int m=tree[rt].mid();
    if(r<=m)update(c,l,r,rt*2);
    else if(l>m)update(c,l,r,rt*2+1);
    else
    {
        update(c,l,m,rt*2);
        update(c,m+1,r,rt*2+1);
    }
    pushup(rt);
}

LL query(int l,int r,int rt)
{
    if(tree[rt].l==l && tree[rt].r==r)return sum[rt];
    pushdown(rt,tree[rt].r-tree[rt].l+1);
    int m=tree[rt].mid();
    LL res=0;
    if(r<=m)res+=query(l,r,rt*2);
    else if(l>m)res+=query(l,r,rt*2+1);
    else
    {
        res+=query(l,m,rt*2);
        res+=query(m+1,r,rt*2+1);
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        build(1,n,1);
        while(k--)
        {
            char ch[2];
            scanf("%s",ch);
            if(ch[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a,b,1));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(c,a,b,1);
            }
        }
    }
    return 0;
}

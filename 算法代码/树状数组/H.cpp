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

int M[maxn],n,k,used[maxn],a[maxn],x,y;

int lowbit(int x)
{
    return x&(-x);
}

void build(int i,int val)
{
    while(i<=n)
    {
        if(used[i]==0){M[i]=val;used[i]++;}
        else
        {
            M[i]=max(M[i],val);
        }
        i+=lowbit(i);
    }
}

void update(int pos,int val)
{
    a[pos]=val;
    for(int i=pos;i<=n;i+=lowbit(i))
    {
        M[i]=a[i];
        if(lowbit(i)>1)
        {
            for(int j=i-1;j>=(i-lowbit(i)+1);j-=lowbit(j))
            {
                M[i]=max(M[i],M[j]);
            }
        }
    }
}

int query(int l,int r)
{
    int res=a[r];
    while(true)
    {
        res=max(res,a[r]);
        if(l==r)break;
        for(r=r-1;r-l>=lowbit(r);r-=lowbit(r))
        {
            res=max(res,M[r]);
        }
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            build(i,a[i]);
        }
        for(int i=0;i<k;i++)
        {
            char op[5];
            scanf("%s%d%d",op,&x,&y);
            if(op[0]=='Q')
            {
                printf("%d\n",query(x,y));
            }
            else
            {
                update(x,y);
            }
        }
    }
    return 0;
}

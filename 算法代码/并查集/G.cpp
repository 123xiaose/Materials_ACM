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
const int maxn=1005;
const int INF=1e18;

using namespace std;

//-------------------------------

int pre[maxn],T,n,m,res,a,b;

void init(int n)
{
    for(int i=1;i<=n;i++)pre[i]=i;
}

int Find(int x)
{
    if(pre[x]==x)return x;
    else
        return pre[x]=Find(pre[x]);
}

void unite(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y)return;
    else
    {
        pre[x]=y;
    }
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&n,&m);
            init(n);res=0;
            for(int i=0;i<m;i++)
            {
                scanf("%d%d",&a,&b);
                unite(a,b);
            }
            //for(int i=1;i<=n;i++)Find(i);
            for(int i=1;i<=n;i++)
            {
                if(pre[i]==i)res++;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}

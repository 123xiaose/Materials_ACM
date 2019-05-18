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
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int n,k;
double y[maxn],x;

struct Node
{
    int v,w;
    bool operator<(const Node &a)const
    {
        return v-x*w>a.v-x*a.w;
    }
}node[maxn];

bool check(double mid)
{
    x=mid;
    sort(node,node+n);
    double tol_v=0,tol_w=0;
    for(int i=0;i<n-k;i++)
    {
        tol_v+=node[i].v;
        tol_w+=node[i].w;
    }
    return tol_v/tol_w>mid;
}

void solve()
{
    double lb=0,ub=(double)(INF);
    while(abs(ub-lb)>1e-4)
    {
        double mid=(ub+lb)/2;
        if(check(mid))lb=mid;
        else
            ub=mid;
    }
    printf("%.0lf\n",lb*100);
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)break;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&node[i].v);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&node[i].w);
        }
        solve();
    }
    return 0;
}

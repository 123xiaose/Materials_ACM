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
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int n,m;
int x[maxn];

bool check(int d)
{
    int last=0;
    for(int i=1;i<m;i++)
    {
        int crt=last+1;
        while(crt<n && x[crt]-x[last]<d)
        {
            crt++;
        }
        if(crt==n)return false;
        last=crt;
    }
    return true;
}

void solve()
{
    sort(x,x+n);
    int lb=0,ub=INF;
    while(ub-lb>1)
    {
        int mid=(ub+lb)/2;
        if(check(mid))lb=mid;
        else
            ub=mid;
    }
    //printf("lb=%d ub=%d\n",lb,ub);
    printf("%d\n",lb);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        solve();
    }
    return 0;
}

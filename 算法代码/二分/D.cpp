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
const int maxn=1e4+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int str[maxn],n,m,T;

bool check(double x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(int)(Pi*str[i]*str[i]/x);
    }
    return sum>=(m+1);
}

void solve()
{
    double lb=0.0,ub=(double)(INF);
    for(int i=0;i<100;i++)
    {
        double mid=(lb+ub)/2.0;
        if(check(mid))lb=mid;
        else
            ub=mid;
    }
    printf("%.4lf\n",ub);
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++)scanf("%d",&str[i]);
            solve();
        }
    }
    return 0;
}

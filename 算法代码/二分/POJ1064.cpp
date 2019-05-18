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
const int maxn=1e4+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

double num[maxn];
int k,n;

bool check(double x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(int)(num[i]/x);
    }
    return sum>=k;
}

void solve()
{
    bool flag=0;
    double lb=0.0,ub=inf;
    for(int i=0;i<100;i++)
    {
        double mid=(lb+ub)/2;
        if(check(mid)){lb=mid;}
        else
            ub=mid;
    }
    printf("%.2f\n",floor(ub*100)/100);
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)break;
        //printf("%d %d\n",n,k);
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&num[i]);
            //cin>>num[i];
        }

        //for(int i=0;i<n;i++)printf("%.2lf ",num[i]);
        //printf("\n");
        solve();
    }
    return 0;
}

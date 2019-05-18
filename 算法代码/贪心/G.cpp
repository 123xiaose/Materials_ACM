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
const int maxn=1e6+5;
const int INF=1e18;

using namespace std;


//-----------------------------
ll N,t,sum,res;
double a,b;
struct cow
{
    ll T;
    ll D;
    double f;
}C[maxn];

bool cmp(cow A,cow B)
{
    return A.f<B.f;
}

int main()
{
    while(~scanf("%lld",&N))
    {
        sum=0;t=0;res=0;
        for(ll i=0;i<N;i++)
        {
            scanf("%lld%lld",&C[i].T,&C[i].D);
            a=double(C[i].T);
            b=double(C[i].D);
            C[i].f=double(a/b);
            sum+=C[i].D;
        }
        sort(C,C+N,cmp);
        for(ll i=0;i<N;i++)
        {
            t=2*C[i].T;
            sum-=C[i].D;
            res+=t*sum;
        }
        printf("%lld\n",res);
    }
    return 0;
}

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
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------
typedef pair<int,int> PII;

ll n;
vector<PII>res;

bool cmp(PII a,PII b)
{
    return a.first<b.first;
}

void solve()
{
    res.clear();
    ll sum=0,s=1,e=1;
    while(s*s<=n && e*e<=n)
    {
        while(e*e<=n && sum<n)
        {
            sum+=e*e;
            ++e;
        }
        while(sum>n)
        {
            sum-=s*s;
            ++s;
        }
        if(sum==n)
        {
            res.push_back(make_pair(e-s,s));
            sum-=s*s;
            ++s;
        }
    }
}

int main()
{
    while(~scanf("%lld",&n))
    {
        solve();
        sort(res.begin(),res.end(),cmp);
        printf("%d\n",res.size());
        for(int i=res.size()-1;i>=0;i--)
        {
            printf("%d ",res[i].first);
            for(int j=res[i].second;j<res[i].first+res[i].second;j++)
            {
                printf("%d ",j);
            }
            printf("\n");
        }
    }
    return 0;
}

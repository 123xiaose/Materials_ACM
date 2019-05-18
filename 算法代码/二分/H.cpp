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

int str[maxn],n;
ll C(int m)
{
    ll res=n*(n-1)/2;
    return res;
}

bool check(int x)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        //printf("%d ",(str+n)-lower_bound(str+i+1,str+n,x+str[i]));
        sum+=(str+n)-lower_bound(str+i+1,str+n,x+str[i]);
    }
    return sum<=C(n)/2;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int cnt=0;
        memset(str,0,sizeof(str));
        for(int i=0;i<n;i++)scanf("%d",&str[i]);
        sort(str,str+n);
        int lb=0,ub=str[n-1]-str[0];
        while(ub-lb>1)
        {
            int mid=(ub+lb)/2;
            if(check(mid))ub=mid;
            else
                lb=mid;
        }
        printf("%d\n",lb);
    }
    return 0;
}

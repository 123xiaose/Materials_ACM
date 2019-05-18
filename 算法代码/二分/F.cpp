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
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int str[maxn],n,m,num,sum;

bool check(int x)
{
    int cnt=0,last;
    for(int i=0;i<n;)
    {
        int tol=str[i];
        last=i+1;
        while(tol+str[last]<=x)
        {
            tol+=str[last];
            last++;
        }
        i=last;
        cnt++;
    }
    return cnt<=m;
}

void solve()
{
    int lb=num,ub=sum;
    while(lb<ub)
    {
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid-1;
        else
            lb=mid+1;
    }
    printf("%d\n",lb);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        num=-INF;sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&str[i]);
            num=max(num,str[i]);
            sum+=str[i];
        }
        solve();
    }
    return 0;
}

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

int used[maxn],str[maxn],need[maxn],n,m;

bool check(int x)
{
    int sum=0,cnt=0;
    memset(used,0,sizeof(used));
    for(int i=x;i>=1;i--)
    {
        if(!used[str[i]] && str[i])
        {
            sum+=need[str[i]];
            used[str[i]]=1;
            cnt++;
        }
        else if(sum>0)
        {
            sum--;
        }
    }
    if(sum!=0 || cnt!=m)return false;
    else
        return true;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int ans=INF,flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&str[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&need[i]);
        }
        int lb=1,ub=n,mid;
        while(lb<=ub)
        {
            mid=(ub+lb)/2;
            if(check(mid))
            {
                flag=1;
                ub=mid-1;
                ans=min(ans,mid);
            }
            else
                lb=mid+1;
        }
        if(flag)printf("%d",ans);
        else
            printf("-1\n");
    }
    return 0;
}

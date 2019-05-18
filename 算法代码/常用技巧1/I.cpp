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
int str[1005],n;
map<int,PII>mp;


bool judge(int sum,int i,int j)
{
    if(!mp.count(sum))return false;
    else
    {
        if(i==mp[sum].first || i==mp[sum].second)return false;
        if(j==mp[sum].first || j==mp[sum].second)return false;
    }
    return true;
}

void solve()
{
    int res,flag=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            int tmp=str[i]-str[j];
            if(judge(tmp,i,j))
            {
                res=str[i];
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    if(flag)printf("%d\n",res);
    else
        printf("no solution\n");
}


int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        mp.clear();
        memset(str,0,sizeof(str));
        for(int i=0;i<n;i++)scanf("%d",&str[i]);
        sort(str,str+n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int tmp=str[i]+str[j];
                mp.insert(make_pair(tmp,PII(i,j)));
            }
        }
        solve();
    }
    return 0;
}

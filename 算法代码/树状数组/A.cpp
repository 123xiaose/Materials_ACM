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
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=2*1e4+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;
//-----------------------------------

pair<int,int>cow[maxn];
int n;
LL dis[maxn],cnt[maxn];

int lowbit(int x)
{
    return x&(-x);
}

LL sum(LL *bit,int i)
{
    LL res=0;
    while(i>0)
    {
        res+=bit[i];
        i-=lowbit(i);
    }
    return res;
}

LL sum(LL *bit,int from,int to)
{
    return sum(bit,to-1)-sum(bit,from-1);
}

void update(LL *bit,int i,LL val)
{
    while(i<maxn)
    {
        bit[i]+=val;
        i+=lowbit(i);
    }
}


int main()
{
    while(~scanf("%d",&n))
    {
        //cow.clear();
        for(int i=0;i<n;i++)scanf("%lld%lld",&cow[i].first,&cow[i].second);
        sort(cow,cow+n);
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            int v=cow[i].first,x=cow[i].second;
            LL left=sum(cnt,1,x),right=sum(cnt,x+1,maxn);
            ans+=v*(left*x-sum(dis,1,x)+sum(dis,x+1,maxn)-right*x);
            update(cnt,cow[i].second,1);
            update(dis,cow[i].second,cow[i].second);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

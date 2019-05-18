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
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------
int n,a,b,used[maxn];

struct Node
{
    int s,e;
}node[105];

bool cmp(Node a,Node b)
{
    if(a.e==b.e)return a.s<b.s;
    else
        return a.e<b.e;
}

bool check(int x)
{
    int cnt=0;
    memset(used,0,sizeof(used));
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=node[i].s+1;j<=node[i].e;j++)
        {
            if(!used[j])
            {
                used[j]=1;
                if(++cnt==x)break;
            }
        }
        if(cnt<x)return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)scanf("%d%d",&node[i].s,&node[i].e);
        sort(node,node+n,cmp);
        int lb=0,ub=INF;
        for(int i=0;i<100;i++)
        {
            int mid=(ub+lb)/2;
            if(check(mid))lb=mid;
            else
                ub=mid;
        }
        printf("%d\n",lb*n);
    }
    return 0;
}

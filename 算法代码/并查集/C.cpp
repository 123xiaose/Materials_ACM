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
const int maxn=200000;
const int INF=1e18;

using namespace std;

//-------------------------------

int pre[maxn],sum[maxn],N,M,res,a,b,v;

int Find(int x)
{
    if(pre[x]==-1)return x;
    int temp=Find(pre[x]);
    sum[x]+=sum[pre[x]];
    //int temp=Find(pre[x]);
    return pre[x]=temp;
}

void unite(int x,int y,int v)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        if(fx>fy)
        {
            pre[fx]=fy;
            sum[fx]=abs(sum[y]-sum[x]-v);
        }
        else if(fx<fy)
        {
            pre[fy]=fx;
            sum[fy]=abs(sum[x]-sum[y]+v);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        res=0;
        memset(pre,-1,sizeof(pre));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&a,&b,&v);
            a--;
            int fa=Find(a);
            int fb=Find(b);
            if(fa==fb)
            {
                if(abs(sum[b]-sum[a])!=v)res++;
            }
            else if(fa!=fb)
            {
                unite(a,b,v);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

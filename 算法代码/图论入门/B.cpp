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
typedef long L;
typedef long long LL;
typedef unsigned long long uLL;
const double Pi=3.1415926;
const int mod=1e9+7;
const int maxn=1000000+10;
const int maxm=1000000+10;
const int INF=0x3f3f3f3f;

using namespace std;

//-----------------------------------
struct edge
{
    LL u,v,w;
};

LL d[maxn];
LL n,m,u[maxn],v[maxn],w[maxn],T,res;
LL cnt[maxn],inq[maxn];
vector<LL>g[maxn];
vector<edge>Edge;

void addedge(LL u,LL v,LL w)
{
    edge temp;
    temp.u=u;
    temp.v=v;
    temp.w=w;
    Edge.push_back(temp);
    g[u].push_back(Edge.size()-1);
}

void spfa(LL u)
{
    memset(d,INF,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    memset(inq,0,sizeof(inq));
    d[u]=0;cnt[u]=1;inq[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        LL t=q.front();q.pop();
        inq[t]=0;
        for(LL k=0;k<g[t].size();k++)
        {
            edge e=Edge[g[t][k]];
            if(d[e.v]>d[e.u]+e.w)
            {
                d[e.v]=d[e.u]+e.w;
                if(!inq[e.v])
                {
                    inq[e.v]=1;
                    //if(++cnt[e.v]>n)return false;
                    q.push(e.v);
                }
            }
        }
    }
    for(LL i=1;i<n;i++)
    {
        res+=d[i];
    }
}

int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        res=0;
        Edge.clear();
        scanf("%lld%lld",&n,&m);
        for(LL i=0;i<n;i++)g[i].clear();
        for(LL i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
            u[i]--;v[i]--;
            addedge(u[i],v[i],w[i]);
        }
        spfa(0);
        Edge.clear();
        for(LL i=0;i<n;i++)g[i].clear();
        for(LL i=0;i<m;i++)addedge(v[i],u[i],w[i]);
        spfa(0);
        printf("%lld\n",res);
    }
    return 0;
}


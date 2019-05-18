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
const int maxn=105;
const int INF=0x3f3f3f3f;

using namespace std;

//-----------------------------------

int ednum,head[maxn],vis[maxn],cnt[maxn],n,m;
double d[maxn];

struct edge
{
    int to,next;
    double w;
}Edge[maxn*maxn];

void add(int u,int v,double c)
{
    Edge[ednum].to=v;
    Edge[ednum].w=c;
    Edge[ednum].next=head[u];
    head[u]=ednum++;
}

void init()
{
    memset(head,-1,sizeof(head));
    ednum=0;
}

bool spfa(int u)
{
    for(int i=0;i<=n;i++)
    {
        d[i]=INF*1.0;cnt[i]=0;vis[i]=0;
    }
    d[u]=0.0;cnt[u]=1;vis[u]=1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        vis[t]=0;
        for(int i=head[t];i!=-1;i=Edge[i].next)
        {
            int v=Edge[i].to;
            double w=Edge[i].w;
            if(d[v]>d[t]+w)
            {
                d[v]=d[t]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                    if(++cnt[v]>=n)return 0;
                }
            }
        }
    }
    return 1;
}

bool check(double x)
{
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=head[i];k!=-1;k=Edge[k].next)
        {
            Edge[k].w-=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!spfa(i))
        {
            flag=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=head[i];k!=-1;k=Edge[k].next)
        {
            Edge[k].w+=x;
        }
    }
    return flag;
}

int main()
{
    int t,kase=1,a,b;
    double w,l=INF*1.0,r=0.0,mid=0.0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lf",&a,&b,&w);
            l=min(l,w);
            r=max(r,w);
            add(a,b,w);
        }
        printf("Case #%d: ",kase++);
        if(!check(r+1))
        {
            printf("No cycle found.\n");
        }
        else
        {
            double s=1e-5;
            while(r-l>s)
            {
                mid=(r+l)/2.0;
                if(check(mid))
                {
                    r=mid;
                }
                else
                    l=mid;
            }
            printf("%.2f\n",r);
        }
    }
    return 0;
}

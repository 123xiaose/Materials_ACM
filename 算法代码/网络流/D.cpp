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
#include<utility>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926;
const LL mod=1e9+7;
const int maxn=116*116*2;
const int maxm=116*116*2;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------
#define type int
typedef pair<int,int> P;
char ch;
int n,m;

//s源点t汇点N总点数
int s, t;
struct node {
    int u, v, next;
    type cap, flow, cost;
}edge[maxm];
int head[maxn], cnt;
int pre[maxn];
type dis[maxn];
bool vis[maxn];
int N;

void init () {
    memset (head, -1, sizeof head);
    cnt = 0;
}

void add_edge (int u, int v, type cap, type cost) {
    edge[cnt].u = u, edge[cnt].v = v, edge[cnt].cap = cap, edge[cnt].flow = 0;
    edge[cnt].cost = cost, edge[cnt].next = head[u], head[u] = cnt++;
    edge[cnt].u = v, edge[cnt].v = u, edge[cnt].cap = 0, edge[cnt].flow = 0;
    edge[cnt].cost = -cost, edge[cnt].next = head[v], head[v] = cnt++;
}

bool spfa (int s, int t) {
    queue <int> q;
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = 0;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = 1;
    q.push (s);
    while (!q.empty ()) {
        int u = q.front (); q.pop ();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].cap > edge[i].flow && dis[v] > dis[u]+edge[i].cost) {
                dis[v] = dis[u]+edge[i].cost;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push (v);
                }
            }
        }
    }
    if (pre[t] == -1)
        return 0;
    else
        return 1;
}

int MCMF (int s, int t, type &cost) {
    type flow = 0;
    cost = 0;
    while (spfa (s, t)) {
        type Min = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i^1].v]) {
            if (Min > edge[i].cap-edge[i].flow) {
                Min = edge[i].cap-edge[i].flow;
            }
        }
        for (int i = pre[t]; i != -1; i = pre[edge[i^1].v]) {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost*Min;
        }
        flow += Min;
    }
    return flow;
}

int dis_p(pair<int,int> a,pair<int,int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if( n==0 && m==0 )break;
        //man.clear();hom.clear();
        init();
        vector<P>man;vector<P>hom;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ch;
                if(ch=='m')man.push_back(make_pair(i,j));
                else if(ch=='H')hom.push_back(make_pair(i,j));
            }
        }
        int siz=man.size();
        s=0;t=1+siz*2;
        N=siz*2+2;
        for(int i=0;i<siz;i++)
        {
            add_edge(s,i+1,1,0);
            add_edge(i+1+siz,t,1,0);
            for(int j=0;j<siz;j++)
            {
                add_edge(i+1,siz+j+1,1,dis_p(man[i],hom[j]));
            }
        }
        int cost=0;
        MCMF(s,t,cost);
        printf("%d\n",cost);
    }
    return 0;
}

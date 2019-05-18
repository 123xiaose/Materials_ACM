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
const int maxn=1000+5;
const int INF=1e18;

using namespace std;

//-----------------------------
int T,n,D,ans=0,visit[maxn];
struct Node
{
    int d,v;
}node[maxn];

bool cmp(Node a,Node b)
{
    if(a.v==b.v)return a.d<b.d;
    else
        return a.v>b.v;
}

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d",&n);ans=0;
            memset(visit,0,sizeof(visit));
            memset(node,0,sizeof(node));
            for(int i=1;i<=n;i++)scanf("%d",&node[i].d);
            for(int i=1;i<=n;i++)scanf("%d",&node[i].v);
            sort(node+1,node+n+1,cmp);
            //for(int i=1;i<=n;i++)printf("%d %d\n",node[i].d,node[i].v);
            for(int i=1;i<=n;i++)
            {
                int j=node[i].d;
                while(j)
                {
                    if(!visit[j])
                    {
                        visit[j]=1;
                        break;
                    }
                    j--;
                }
                if(j==0)ans+=node[i].v;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

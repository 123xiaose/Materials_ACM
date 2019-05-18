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
const int maxn=10005;
const int INF=1e18;

using namespace std;


//-----------------------------

struct Node
{
    int x,y;
}node[maxn];

bool cmp(Node a,Node b)
{
    return a.x<b.x;
}
int N,pos,tank,ans,L,P;

priority_queue<int>que;

int main()
{
    while(~scanf("%d",&N))
    {
       for(int i=0;i<N;i++)
       {
           scanf("%d%d",&node[i].x,&node[i].y);
       }
       scanf("%d%d",&L,&P);
       ans=0;pos=0;tank=P;
       for(int i=0;i<N;i++){node[i].x=L-node[i].x;}
       node[N].x=L;node[N].y=0;N++;
       sort(node,node+N,cmp);
       //for(int i=0;i<N;i++)printf("%d %d\n",node[i].x,node[i].y);
       for(int i=0;i<N;i++)
       {
           int dis=node[i].x-pos;
           while(tank<dis)
           {
               if(que.empty())
               {
                   ans=-1;
                   goto there;
               }
               tank+=que.top();
               que.pop();
               ans++;
               //printf("%d %d %d\n",tank,ans,i);
           }
           tank=tank-dis;
           pos=node[i].x;
           que.push(node[i].y);
       }
       there:
           printf("%d\n",ans);
    }
    return 0;
}

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
const int maxn=50000+5;
const int INF=1e18;

using namespace std;


//-----------------------------
struct Node
{
    int st,en,pos;
    friend bool operator<(Node a,Node b)
    {
        if(a.en==b.en)
            return a.st<b.st;
        else
            return a.en>b.en;
    }
}node[maxn];

bool cmp(Node a,Node b)
{
    if(a.st==b.st)
        return a.en<b.en;
    else
        return a.st<b.st;
}

priority_queue<Node>Q;

int pos[maxn];

int main()
{
    int N,ans;
    while(~scanf("%d",&N))
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&node[i].st,&node[i].en);
            node[i].pos=i;
        }
        sort(node+1,node+1+N,cmp);
        Q.push(node[1]);
        ans=1;
        pos[node[1].pos]=1;
        for(int i=2;i<=N;i++)
        {
            if(!Q.empty() && node[i].st>Q.top().en)
            {
                pos[node[i].pos]=pos[Q.top().pos];
                Q.pop();
            }
            else
            {
                ans++;
                pos[node[i].pos]=ans;
               // Q.pop();
            }
            Q.push(node[i]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=N;i++)
        {
            printf("%d\n",pos[i]);
        }
    }
    return 0;
}

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
const int maxn=100005;
const int INF=1e18;

using namespace std;

//-------------------------------
int pre[maxn],a,b,num1,num2,visit[maxn],flag;
void init()
{
    for(int i=0;i<maxn;i++)
    {
        pre[i]=i;
        visit[i]=0;
    }
    num1=0;num2=0;flag=0;
}

int Find(int x)
{
    if(pre[x]==x)return x;
    else
    {
        return pre[x]=Find(pre[x]);
    }
}

void unite(int x,int y)
{
    if(x==y)flag=1;
    x=Find(x);
    y=Find(y);
    if(x==y)flag=1;
    else
    {
        pre[x]=y;
        num1++;
    }
}

bool same(int x,int y)
{
    return Find(x)==Find(y);
}

int main()
{
    while(1)
    {
        init();
        scanf("%d%d",&a,&b);
        if(a==-1&&b==-1)break;
        if(a==0&&b==0)
        {
            printf("Yes\n");
            continue;
        }
        visit[a]=1;
        visit[b]=1;
        unite(a,b);
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a==0&&b==0)break;
            visit[a]=1;
            visit[b]=1;
            unite(a,b);
        }
        for(int i=0;i<maxn;i++)
        {
            if(visit[i])num2++;
        }
        if(!flag&&num1==num2-1)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}

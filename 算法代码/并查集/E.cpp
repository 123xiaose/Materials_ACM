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
const int maxn=1001+16;
const int INF=1e18;

using namespace std;

//-------------------------------

int pre[maxn],srank[maxn],d,n;
char op;
bool able[maxn][maxn];

struct Point
{
    int x,y;
    bool flag;
}p[maxn];

void init(int n)
{
   for(int i=0;i<n;i++)
   {
       pre[i]=i;
       srank[i]=0;
   }
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
    x=Find(x);
    y=Find(y);
    if(x==y)return;
    else
    {
        if(srank[x]<srank[y])
        {
            pre[x]=y;
        }
        else
        {
            pre[y]=x;
            if(srank[x]==srank[y])++srank[x];
        }
    }
}

bool same(int x,int y)
{
    return Find(x)==Find(y);
}

int dis(Point a,Point b)
{
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    init(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(dis(p[i],p[j])<=d*d)
            {
                able[i][j]=true;
                able[j][i]=true;
            }
        }
    }
    while(cin>>op)
    {
        if(op=='O')
        {
            int x;
            scanf("%d",&x);
            x--;
            p[x].flag=true;
            for(int i=0;i<n;i++)
            {
                if(i!=x&&p[i].flag&&able[x][i])
                {
                    unite(x,i);
                }
            }
        }
        else
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            if(same(a,b))printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}

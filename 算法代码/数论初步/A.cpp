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
#include<uility>
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
const int INF=0x3f3f3f3f;

using namespace std;

//-----------------------------------

pair<int,int>p;
int vis[maxn];
int str[maxn],T,n,kase;

void init()
{
    vis[0]=vis[1]=1;
    for(int i=2;i<maxn;i++)
    {
        for(int j=2*i;j<maxn;j+=i)vis[j]=1;
    }
}

void euler()
{
    for(int i=1;i<maxn;i++)
        str[i]=i;
    for(int i=2;i<maxn;i++)
    {
        if(str[i]==i)
        {
            for(int j=i;j<maxn;j+=i)
            {
                str[j]=str[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    init();
    euler();
    str[1]=3;
    for(int i=2;i<maxn;i++)
    {
        str[i]=str[i-1]+2*str[i];
    }
    while(~scanf("%d",&T))
    {
        kase=0;
        while(T--)
        {
            scanf("%d",&n);
            printf("%d %d %d\n",++kase,n,str[n]);
        }
    }
    return 0;
}

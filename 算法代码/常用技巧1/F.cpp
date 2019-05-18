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
#include<utility>
#include<map>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e4+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int str[25],f[25],n=21;

int solve(int x)
{
    memset(f,0,sizeof(f));
    int res=0,sum=0;
    str[0]=x;
    for(int i=0;i<n-1;++i)
    {
        if( (str[i]+sum)%2==1 )
        {
            ++res;
            f[i]=1;
        }
        sum+=f[i];
        if(i-2>=0)sum-=f[i-2];
    }
    if( (str[n-1]+sum)%2==1 )return INF;
    return res;
}

int main()
{
    while(~scanf("%d",&str[1]))
    {
        for(int i=2;i<=20;i++)scanf("%d",&str[i]);
        printf("%d\n",min(solve(0),solve(1)));
    }
    return 0;
}

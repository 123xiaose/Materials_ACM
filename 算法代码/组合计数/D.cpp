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
const int maxn=1111;
const int maxm=21111;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

LL c[maxm][maxn],m;
int n;

map<int,int>mp;

void init()
{
    c[0][0]=1;
    for(int i=1;i<maxm;i++)
    {
        for(int j=0;j<=i&&j<maxn;j++)
        {
            if(j==0 || j==i)c[i][j]=1;
            else
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}

void solve(LL x)
{
    for(int j=2;j*j<=x;j++)
    {
        if(x%j==0)
        {
            int cnt=0;
            while(x%j==0)
            {
                cnt++;
                x=x/j;
            }
            mp[j]+=cnt;
        }
        //if(x!=1)mp[x]+=1;
    }
    if(x!=1)mp[x]+=1;
}

int main()
{
    init();
    while(~scanf("%d",&n))
    {
        mp.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&m);
            //printf("%lld ",C(n,m));
            solve(m);
        }
        LL res=1;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int num=(*it).second;
            res=(res*c[num+n-1][n-1])%mod;
        }
        printf("%lld\n",res);
    }
    return 0;
}

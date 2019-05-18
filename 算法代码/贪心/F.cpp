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

struct Money
{
    ll v,cnt;
}M[25];

bool cmp(Money a,Money b)
{
    return a.v>b.v;
}

int main()
{
    ll N,C,i,j;
    ll res=0;
    while(~scanf("%lld%lld",&N,&C))
    {
        res=0;
        for(i=0;i<N;i++)
        {
            scanf("%lld%lld",&M[i].v,&M[i].cnt);
        }
        sort(M,M+N,cmp);
        for(j=0;j<N;j++)
        {
            if(M[j].v>=C)
            {
                res+=M[j].cnt;
                M[j].cnt=0;
            }
            else if(M[j].v<C)break;
        }
        while(1)
        {
            ll now=0;
            for(i=0;i<N;i++)
            {
                while( M[i].cnt && (M[i].v+now)<C )
                {
                    now+=M[i].v;
                    M[i].cnt--;
                }
            }
            for(i=N-1;i>=0;i--)
            {
                while( M[i].cnt && now<C)
                {
                    now+=M[i].v;
                    M[i].cnt--;
                }
            }
            if(now<C)break;
            res++;
        }
        printf("%lld\n",res);
    }
    return 0;
}

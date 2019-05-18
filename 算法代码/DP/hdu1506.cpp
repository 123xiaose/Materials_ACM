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
const int maxn=100000+5;
const int INF=1e7;

using namespace std;

//-----------------------------

ll L[maxn],r[maxn],h[maxn];
int N;

int main()
{
    while(~scanf("%d",&N))
    {
        if(N==0)break;
        memset(L,0,sizeof(L));
        memset(r,0,sizeof(r));
        memset(h,0,sizeof(h));
        for(int i=1;i<=N;i++)
        {
            scanf("%lld",&h[i]);
            L[i]=i;
            r[i]=i;
        }
        for(int i=1;i<=N;i++)
        {
            while(L[i]>=1&&h[L[i]-1]>=h[i])
            {
                L[i]=L[L[i]-1];
            }
        }
        for(int i=N;i>=1;i--)
        {
            while(r[i]>=1&& h[r[i]+1]>=h[i])
            {
                r[i]=r[r[i]+1];
            }
        }
        //for(int i=1;i<=N;i++)printf("%lld %lld %lld\n",L[i],r[i],h[i]);
        ll res=-INF,temp;
        for(int i=1;i<=N;i++)
        {
            temp=(r[i]-L[i]+1)*h[i];
            if(temp>=res)
            {
                res=temp;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}

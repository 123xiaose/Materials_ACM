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
const double Pi=3.1415926535898;
const int mod=1e9+7;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

int str[maxn],f[maxn],M,K,n;
char ch;

int solve(int k)
{
    memset(f,0,sizeof(f));
    int sum=0,res=0;
    for(int i=0;i+k<=n;i++)
    {
        if((str[i]+sum)%2!=0)
        {
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-k+1>=0)
        {
            sum-=f[i-k+1];
        }
    }
    for(int i=n-k+1;i<n;i++)
    {
        if( (str[i]+sum)%2!=0 )return -1;
        if(i-k+1>=0)sum-=f[i-k+1];
    }
    return res;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='F')str[i]=0;
            else if(ch=='B')str[i]=1;
        }
        int K=1,M=n;
        for(int k=1;k<=n;k++)
        {
            int m=solve(k);
            if(m>=0 && m<M)
            {
                M=m;
                K=k;
            }
        }
        printf("%d %d\n",K,M);
    }
    return 0;
}

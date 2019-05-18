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
const int maxm=1111;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

int a[maxn];
char str[maxn];

LL c[maxn][maxn];

void init()
{
    c[0][0]=1;
    for(int i=1;i<maxn;i++)
    {
        for(int j=0;j<=i&&j<maxn;j++)
        {
            if(j==0 || j==i)c[i][j]=1;
            else
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}

int main()
{
    init();
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            memset(a,0,sizeof(a));
            scanf("%s",str);
            int len=strlen(str);
            if(len==1)
            {
                printf("1\n");
                continue;
            }
            for(int i=0;i<len;i++)
            {
                a[str[i]-'a']++;
            }
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(a[i]&1)cnt++;
            }
            if(cnt>1){printf("0\n");continue;}
            int sum=0;LL res=1;
            for(int i=0;i<26;i++)
            {
                a[i]=a[i]/2;sum+=a[i];
            }
            for(int i=0;i<26;i++)
            {
                res=res*c[sum][a[i]]%mod;
                sum-=a[i];
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}

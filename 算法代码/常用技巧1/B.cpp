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

int str[maxn],T,n,m,sum[maxn],res;

int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            memset(str,0,sizeof(str));
            memset(sum,0,sizeof(sum));
            scanf("%d%d",&n,&m);
            int flag=0;
            for(int i=0;i<n;i++)scanf("%d",&str[i]);
            //sort(str,str+n);
            //sum[0]=str[0];
            for(int i=0;i<n;i++)sum[i+1]=sum[i]+str[i];
            for(int i=0;sum[i]+m<=sum[n];i++)
            {
                int *temp=lower_bound(sum+i,sum+n,sum[i]+m);
                if( (*temp-sum[i])%m==0 ){flag=1;break;}
            }
            if(flag)printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

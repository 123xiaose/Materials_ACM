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
const int maxn=5000005;
const int INF=1e7;

using namespace std;
//-----------------------------
int str[50],dp[maxn];

int main()
{
    int n;
    double q;
    while(~scanf("%lf%d",&q,&n))
    {
        if(n==0)break;
        int w=q*100,t=0;
        for(int i=0,flag=1,m;i<n;++i,flag=1)
        {
            scanf("%d",&m);
            double sum=0.0,c[3]={0,0,0};
            while(m--)
            {
                getchar();
                char ch1;double money;
                scanf("%c:%lf",&ch1,&money);
               // printf("%c%c%.3lf\n",ch1,ch2,money);
                if( (ch1!='A'&&ch1!='B'&&ch1!='C')||money>600.0 )flag=0;
                if(ch1=='A')c[0]+=money;
                if(ch1=='B')c[1]+=money;
                if(ch1=='C')c[2]+=money;
                sum+=money;
            }
            if(c[0]>600.0||c[1]>600.0||c[2]>600.0)flag=0;
            if(sum>1000.0||sum>q||sum<=0)flag=0;
            if(flag) str[t++]=sum*100;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<t;++i)
        {
            for(int j=w;j>=str[i];--j)
            {
                dp[j]=max(dp[j],dp[j-str[i]]+str[i]);
            }
        }
        printf("%.2lf\n",dp[w]/100.0);
    }
    return 0;
}

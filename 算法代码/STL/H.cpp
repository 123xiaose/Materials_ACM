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
const int maxn=5005;
const ll INF=1e14;

using namespace std;


//-----------------------------
int n,m,k,str[maxn],t,x,num;
int visit_r[maxn],time_r[maxn];
int visit_c[maxn],time_c[maxn];

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        memset(str,0,sizeof(str));
        memset(visit_r,0,sizeof(visit_r));
        memset(visit_c,0,sizeof(visit_c));
        memset(time_r,0,sizeof(time_r));
        memset(time_c,0,sizeof(time_c));
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d",&t,&x,&num);
            if(t==1)
            {
                visit_r[x]=num;
                time_r[x]=i;
            }
            if(t==2)
            {
                visit_c[x]=num;
                time_c[x]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(j!=1)printf(" ");
                if(!time_r[i] && !time_c[j] )
                    printf("0");
                else
                {
                    if(time_r[i]>time_c[j])
                    {
                        printf("%d",visit_r[i]);
                    }
                    else
                        printf("%d",visit_c[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

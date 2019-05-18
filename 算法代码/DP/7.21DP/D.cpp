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
const int mod=10000;
const int maxn=100000+2;
const int INF=1e18;

using namespace std;

//-----------------------------

int dpa[200],dpb[200],T,len,i,j;
char str[200];


int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%s",str+1);
            len=strlen(str+1);
            memset(dpa,0,sizeof(dpa));
            memset(dpb,0,sizeof(dpb));
            dpa[0]=0;dpb[0]=1;
            for(i=1;i<=len;i++)
            {
                if( (str[i]>='a')&&(str[i]<='z') )
                {
                    dpa[i]=min(dpa[i-1]+1,dpb[i-1]+2);
                    dpb[i]=min(dpa[i-1]+2,dpb[i-1]+2);
                }
                else if( (str[i]>='A')&&(str[i]<='Z') )
                {
                    dpa[i]=min(dpa[i-1]+2,dpb[i-1]+2);
                    dpb[i]=min(dpa[i-1]+2,dpb[i-1]+1);
                }
            }
            printf("%d\n",min(dpb[i-1]+1,dpa[i-1]));
        }
    }
    return 0;
}

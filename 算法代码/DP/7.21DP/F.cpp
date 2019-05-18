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
const int maxn=200000+5;
const int INF=1e18;

using namespace std;

//-----------------------------

int dpa[maxn],dpb[maxn],row[maxn];
int m,n,ans,num;

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<m;i++)
        {
            dpa[0]=0;dpb[0]=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&num);
                dpa[j+1]=max(dpa[j],dpb[j]);
                dpb[j+1]=dpa[j]+num;
            }
            row[i]=max(dpa[n],dpb[n]);
        }
        dpa[0]=0;dpb[0]=0;
        for(int i=0;i<m;i++)
        {
            dpa[i+1]=max(dpa[i],dpb[i]);
            dpb[i+1]=dpa[i]+row[i];
        }
        ans=max(dpa[m],dpb[m]);
        printf("%d\n",ans);
    }
    return 0;
}

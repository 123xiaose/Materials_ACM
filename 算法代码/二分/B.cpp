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
const int maxn=2e5+5;
const int INF=0x3f3f3f3f;
const double inf=200005.0;

using namespace std;

//-----------------------------------

char a[maxn],b[maxn],temp[maxn];
int c[maxn],len;

bool check(int x)
{
    strcpy(temp,a);
    for(int i=x-1;i>=0;i--)
    {
        temp[c[i]-1]=0;
    }
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(temp[i]==b[cnt])
        {
            cnt++;
        }
        if(cnt==strlen(b))return true;
    }
    if(cnt==strlen(b))return true;
    else
        return false;
}

int main()
{
    while(~scanf("%s %s",a,b))
    {
        //scanf("%s",b);
        len=strlen(a);
        for(int i=0;i<len;i++)scanf("%d",&c[i]);
        //printf("%s\n%s\n",a,b);
        //for(int i=0;i<len;i++)printf("%d ",c[i]);
        //printf("\n");
        int lb=0,ub=len;
        for(int i=0;i<100;i++)
        {
            int mid=(ub+lb)/2;
            if(check(mid))lb=mid;
            else
                ub=mid;
        }
        printf("%d\n",lb);
    }
    return 0;
}

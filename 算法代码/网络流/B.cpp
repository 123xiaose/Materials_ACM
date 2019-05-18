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
const int maxn=205;
const int maxm=1111;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

int n,Cat[105][100];

void init()
{
    int yu,len,i,j;
    Cat[1][0]=1;Cat[1][1]=1;
    Cat[2][0]=1;Cat[2][1]=2;
    len=1;
    for(i=3;i<101;i++)
    {
        yu=0;
        for(j=1;j<=len;j++)
        {
            int tmp=Cat[i-1][j]*(4*i-2)+yu;
            yu=tmp/10;
            Cat[i][j]=tmp%10;
        }
        while(yu)
        {
            Cat[i][++len]=yu%10;
            yu=yu/10;
        }
        for(j=len;j>=1;j--)
        {
            int tmp=Cat[i][j]+yu*10;
            Cat[i][j]=tmp/(i+1);
            yu=tmp%(i+1);
        }
        while(!Cat[i][len])
        {
            len--;
        }
        Cat[i][0]=len;
    }
}

int main()
{
    init();
    while(~scanf("%d",&n))
    {
        for(int i=Cat[n][0];i>=1;i--)printf("%d",Cat[n][i]);
        printf("\n");
    }
    return 0;
}

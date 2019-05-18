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
const int maxn=10010;
const int INF=1e18;

using namespace std;

//-------------------------------

int pre[maxn],re[maxn],k,num,n,res,j;

void init()
{
    k=1;
    for(int i=0;i<maxn;i++)
    {
        pre[i]=-1;
       // re[i]=0;
    }
}

int Find(int x)
{
    if(pre[x]==-1)return x;
    int temp=pre[x];
    pre[x]=Find(pre[x]);
    re[x]=(re[x]+re[temp])%2;
    return pre[x];
}

bool unite(int x,int y,int v)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx==fy)
    {
        if( (re[y]+re[x])%2==v )return true;
        else
            return false;
    }
    else
    {
        pre[fx]=fy;
        re[fx]=(re[x]+re[y]+v)%2;
        return true;
    }
}
map<int,int>mp;

int main()
{
    scanf("%d",&num);
        mp.clear();res=0;
        scanf("%d",&n);
        init();
        for(j=0;j<n;j++)
        {
            int a,b;
            char str[5];
            scanf("%d%d%s",&a,&b,str);
            a--;
           // printf("%d %d %s\n",a,b,str);
            if(mp.count(a)==0)
            {
                mp[a]=k++;
            }
            if(mp.count(b)==0)
            {
                mp[b]=k++;
            }
            int odd;
            if(strcmp(str,"odd")==0)odd=1;
            else
                odd=0;
            if(!unite(mp[a],mp[b],odd))
            {
                res=j;
                break;
            }
        }
        printf("%d\n",res);
    return 0;
}

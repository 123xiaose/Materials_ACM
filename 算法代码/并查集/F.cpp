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

int pre[maxn],re[maxn],k;
map<int,int>mp;

void init()
{
    k=1;
    int i;
    for(i=0;i<maxn;i++)
    {
        pre[i]=-1;
    }
}

int Find(int x)
{
    if(pre[x]==-1)return x;
    int t=pre[x];
    pre[x]=Find(pre[x]);
    re[x]=(re[x]+re[t])%2;
    return pre[x];
}

bool unite(int x,int y,int d)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx==fy)
    {
        if((re[x]+re[y])%2==d)return true;
        else
            return false;
    }
    else
    {
        pre[fx]=fy;
        re[fx]=(re[x]+re[y]+d)%2;
        return true;
    }
}

int main()
{
    int num,n,i;
    init();
    cin>>num>>n;
    //init();
    for(i=0;i<n;i++)
    {
        int a,b;
        string str;
        cin>>a>>b>>str;
        a--;
        if(mp.count(a)==0)
        {
            mp[a]=k++;
        }
        if(mp.count(b)==0)
        {
            mp[b]=k++;
        }
        int odd;
        if(str=="odd")odd=1;
        else
            odd=0;
        if(!unite(mp[a],mp[b],odd))break;
    }
    cout<<i<<endl;
    system("pause");
    return 0;
}

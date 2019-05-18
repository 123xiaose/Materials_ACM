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

int str[maxn],P,res;

int main()
{
    while(~scanf("%d",&P))
    {
        memset(str,0,sizeof(str));
        for(int i=0;i<P;i++)scanf("%d",&str[i]);
        set<int>st;
        for(int i=0;i<P;i++)st.insert(str[i]);
        int n=st.size();
        int s=0,t=0,num=0;
        res=P;map<int,int>mp;
        for(;;)
        {
            while(t<P && num<n)
            {
                if(mp[str[t++]]++==0)num++;
            }
            if(num<n)break;
            res=min(res,t-s);
            if(--mp[str[s++]]==0)num--;
        }
        printf("%d\n",res);
    }
    return 0;
}

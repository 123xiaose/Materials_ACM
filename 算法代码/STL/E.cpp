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
const int maxn=2005;
const ll INF=1e14;

using namespace std;


//-----------------------------

ll k,K,n,f[100050],sum,res;
set<ll>st;
map<ll,ll>mp;
set<ll>::iterator it;
int main()
{
    while(~scanf("%lld%lld",&n,&k))
    {
        st.clear();
        mp.clear();
        f[0]=0;res=0;
       for(ll i=1;i<=n;i++)
       {
          scanf("%lld",&f[i]);
          f[i]+=f[i-1];
       }
       st.insert(1);
       ll temp=k;
       for(ll i=1;i<=60;i++)
       {
           if(temp>INF)break;
           st.insert(temp);
           temp*=k;
       }
       mp[0]=1;
       for(ll i=1;i<=n;i++)
       {
           for(it=st.begin();it!=st.end();it++)res+=mp[f[i]-*it];
           mp[f[i]]++;
       }
       printf("%lld\n",res);
    }
    return 0;
}

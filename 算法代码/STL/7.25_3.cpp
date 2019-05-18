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
const int maxn=100005;
const int INF=1e18;

using namespace std;


//-----------------------------

ll str[maxn],f[maxn],n,sum;
set<ll>st;

bool flag=0;

int main()
{
    while(~scanf("%lld",&n))
    {
        sum=0;flag=0;f[0]=0;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&str[i]);
            sum+=str[i];
            f[i]=f[i-1]+str[i];
        }
        if(sum%2==1){printf("NO\n");continue;}
        else
        {
            for(ll i=n;i>=1;i--)
            {
                if(2*f[i]-sum==0){flag=1;break;}
                else if(2*f[i]-sum>0)
                {
                    st.insert(2*f[i]-sum);
                }
                else
                    break;
            }
            for(ll i=1;i<=n;i++)
            {
                if(st.count(2*str[i]))
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

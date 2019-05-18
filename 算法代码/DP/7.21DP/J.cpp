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
const int maxn=100000+2;
const int INF=1e18;

using namespace std;

//-----------------------------
struct A
{
    ll num;
    bool operator<(const A &a) const
    {
        return num>a.num;
    }
};

const int s[4]={2,3,5,7};
ll ans[5842],cnt,n,kase=0;

int main()
{
    cnt=0;
    priority_queue<A>Q;
    set<ll>str;
    A num1;
    num1.num=1;
    Q.push(num1);
    str.insert(1);
    for(ll i=0;;i++)
    {
        if(cnt==5842)break;
        A x=Q.top();Q.pop();
        ans[cnt]=x.num;
        cnt++;
        for(ll j=0;j<4;j++)
        {
            A x2;
            x2.num=x.num*s[j];
            if(!str.count(x2.num)){str.insert(x2.num),Q.push(x2);}
        }
    }
    //printf("%lld ",ans[5841]);
    while(~scanf("%lld",&n))
    {
        if(n==0)break;
        //if(n>9&&n<21)printf("The %lldth humble number is %lld.\n",n,ans[n-1]);
        if(n%10==1 && n%100!=11)printf("The %lldst humble number is %lld.\n",n,ans[n-1]);
        else if(n%10==2 && n%100!=12)printf("The %lldnd humble number is %lld.\n",n,ans[n-1]);
        else if(n%10==3 && n%100!=13)printf("The %lldrd humble number is %lld.\n",n,ans[n-1]);
        else
            printf("The %lldth humble number is %lld.\n",n,ans[n-1]);
    }
    return 0;
}

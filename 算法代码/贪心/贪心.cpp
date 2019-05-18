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
const int maxn=20005;
const int INF=1e18;

using namespace std;


//-----------------------------


struct A
{
    ll x;
    bool operator<(const A &a) const
    {
        return x>a.x;
    }
};

priority_queue<A>str;

int main()
{
    ll N,num,res;
    while(~scanf("%lld",&N) )
    {
        res=0;
        for(ll i=0;i<N;i++)
        {
            scanf("%lld",&num);
            A a;
            a.x=num;
            str.push(a);
        }
        while(N>1)
        {
            A a=str.top();
            str.pop();
            A b=str.top();
            str.pop();
            num=a.x+b.x;
            A c;
            c.x=num;
            str.push(c);
            res+=num;
            N--;
        }
        printf("%lld\n",res);
    }
    return 0;
}


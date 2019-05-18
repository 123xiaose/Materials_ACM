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
const int maxn=200005;
const int INF=1e18;

using namespace std;


//-----------------------------

struct Point
{
    int a,b;
    bool operator<(const Point &x)const
    {
        if(a==x.a)return b<x.b;
        else
            return a<x.a;
    }
};

multiset<Point>st;
multiset<Point>::iterator it;

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        if(kase>1)printf("\n");
        printf("Case #%d:\n",kase);
        int n,a,b;
        scanf("%d",&n);
        st.clear();
        while(n--)
        {
            scanf("%d%d",&a,&b);
            Point P=(Point){a,b};
            it=st.lower_bound(P);
            if(it==st.begin()||(--it)->b >b)
            {
                st.insert(P);
                it=st.upper_bound(P);
                while(it!=st.end()&& it->b >=b)st.erase(it++);
            }
            printf("%d\n",st.size());
        }
    }
    return 0;
}

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
const int maxn=2505;
const int INF=1e18;

using namespace std;


//-----------------------------
struct A
{
    int x;
    bool operator<(const A &a)const
    {
        return x>a.x;
    }
};
pair<int,int>cow[maxn];
pair<int,int>bot[maxn];
int C,L,res,i,j;
priority_queue<int,vector<int>,greater<int> >que;

int main()
{
    while(~scanf("%d%d",&C,&L))
    {
        for(i=0;i<C;i++)scanf("%d%d",&cow[i].first,&cow[i].second);
        for(i=0;i<L;i++)scanf("%d%d",&bot[i].first,&bot[i].second);
        sort(cow,cow+C);
        sort(bot,bot+L);
        //for(i=0;i<C;i++)printf("%d %d\n",cow[i].first,cow[i].second);
        //for(i=0;i<L;i++)printf("%d %d\n",bot[i].first,bot[i].second);
        res=0;j=0;
        for(i=0;i<L;i++)
        {
            while( (cow[j].first<=bot[i].first)&&j<C )
            {
                //A a;
                //a.x=cow[j].second;
                que.push(cow[j].second);
                j++;
            }
            while(!que.empty() && bot[i].second)
            {
                //A a;
                int x=que.top();
                que.pop();
                if(x<bot[i].first)continue;
                res++;
                bot[i].second--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

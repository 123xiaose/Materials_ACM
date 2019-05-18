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
const int maxn=100000+5;
const ll INF=1e14;

using namespace std;


//-----------------------------
int N,C,F;
struct cow
{
    int srank,s,aid;
};

cow cow_s[maxn],cow_aid[maxn];

bool cmp_s(cow a,cow b)
{
    return a.s<b.s;
}

bool cmp_a(cow a,cow b)
{
    return a.aid<b.aid;
}

int main()
{
    while(~scanf("%d%d%d",&N,&C,&F))
    {
        int half=N/2;
        for(int i=0;i<C;i++)
        {
            scanf("%d%d",&cow_s[i].s,&cow_s[i].aid);
        }
        sort(cow_s,cow_s+C,cmp_s);
        for(int i=0;i<C;i++)cow_s[i].srank=i;
        memcpy(cow_aid,cow_s,sizeof(cow)*C);
        sort(cow_aid,cow_aid+C,cmp_a);
        int lb=0,ub=C,ans=-1;
        while(ub-lb>1)
        {
            int mid=(ub+lb)>>1;
            int left=0,right=0,tol=cow_s[mid].aid;
            for(int i=0;i<C;i++)
            {
                if((cow_aid[i].srank<mid)&&(tol+cow_aid[i].aid<=F)&&(left<N/2))
                {
                    tol+=cow_aid[i].aid;
                    ++left;
                }
                else if ((cow_aid[i].srank > mid) && (tol + cow_aid[i].aid <= F) && (right < N / 2))
		     	{
				    tol += cow_aid[i].aid;
				    ++right;
			    }
            }
            if( (left<N/2)&&(right<N/2) )
            {
                ans=-1;
                break;
            }
            else if(right<N/2)
            {
                ub=mid;
            }
            else if(left<N/2)
            {
                lb=mid;
            }
            else
            {
                ans=cow_s[mid].s;
                lb=mid;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

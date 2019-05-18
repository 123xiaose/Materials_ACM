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
const int maxn=25000+5;
const int INF=1e18;

using namespace std;


//-----------------------------

struct cow
{
    int S;
    int E;
}Cow[maxn];

int res=0,N,T,s=0;

bool cmp(cow A,cow B)
{
    if(A.S==B.S)return A.E>B.E;
    else
        return A.S<B.S;
}

int main()
{
    while(~scanf("%d%d",&N,&T))
    {
        int max_end=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&Cow[i].S,&Cow[i].E);
            max_end=max(max_end,Cow[i].E);
        }
        sort(Cow,Cow+N,cmp);
        if(max_end<T || Cow[0].S!=1)
        {
            printf("-1\n");
            return 0;
        }
        int cur=Cow[0].E;
        int mark=0;
        int i;
        int cnt=1;
        while(cur<T)
        {
            bool flag=0;
            for(i=mark;i<N && Cow[i].S<=cur+1;i++)
            {
                if(Cow[i].E>Cow[mark].E)
                {
                    flag=1;
                    mark=i;
                }
            }
            if(flag==0)
            {
                cnt=-1;
                break;
            }
            cur=Cow[mark].E;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

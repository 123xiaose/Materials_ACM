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

int f[maxn],k,n,len,x,res;
vector<int>vec;
map<int,int>mp;

int main()
{
    while(~scanf("%d%d",&k,&n))
    {
        f[0]=0;mp.clear();vec.clear();
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&f[i]);
            f[i]+=f[i-1];
        }
        sort(f+1,f+1+k);
        len=unique(f+1,f+1+k)-(f+1);
        //printf("%d\n",len);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int j=1;j<=len;j++)
            {
                int temp=x-f[j];
                vec.push_back(temp);
            }
        }
        sort(vec.begin(),vec.end());
        res=0;
        for(int i=0;i<vec.size();i++)
        {
            mp[vec[i]]++;
        }
        for(int i=0;i<vec.size();i++)
        {
            if(mp[vec[i]]>=n)
            {
                res++;
                mp[vec[i]]=0;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

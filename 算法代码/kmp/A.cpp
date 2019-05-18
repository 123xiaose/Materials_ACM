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
#include<utility>
#define In() freopen("in.txt","r",stdin)
#define Out() freopen("out.txt","w",stdout)
typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
const double Pi=3.1415926;
const LL mod=1e9+7;
const int maxn=1e6+5;
const int maxm=1e6+5;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------

int len1,len2,nxt[maxn],n,m,T,x1,x2;
char str1[maxn],str2[maxn];

map<char,int>mp;

int get_min()
{
    int i=0,j=1,k=0;
    while(i<len2 && j<len2 && k<len2)
    {
        int t=str2[(j+k)%len2]-str2[(i+k)%len2];
        if(t==0)k++;
        else
        {
            if(t>0)j+=k+1;
            else
                i+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}

int get_max()
{
    int i=0,j=1,k=0;
    while(i<len2 && j<len2 && k<len2)
    {
        int t=str2[(j+k)%len2]-str2[(i+k)%len2];
        if(t==0)k++;
        else
        {
            if(t<0)j+=k+1;
            else
                i+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return min(i,j);
}
void makeNext()
{
    int i,k,res=0;
    nxt[0]=0;
    for(i=1,k=0;i<len2;i++)
    {
        while(k>0 && str2[k]!=str2[i])k=nxt[k-1];
        if(str2[k]==str2[i])k++;
        nxt[i]=k;
    }
    if(len2%(len2-nxt[len2-1])==0 && nxt[len2-1]!=0)
    {
        res=len2/(len2-nxt[len2-1]);
        printf("%d %d %d %d\n",x1,res,x2,res);
    }
    else
        printf("%d %d %d %d\n",x1,1,x2,1);
}

void kmp()
{
    int i,k,res=0;
    makeNext();
    for(i=0,k=0;i<len1;)
    {
        while(k>0 && str1[i]!=str2[k])k=nxt[k-1];
        if(str2[k]==str1[i])k++;
        if(k==len2){res++;i+=k;}
        else
            i++;
    }
    printf("%d\n",res);
}

int main()
{
    while(~scanf("%s",str2))
    {
        mp.clear();
        //if(len2==0)break;
        //scanf("%s",str2);
        //len1=strlen(str1);
        len2=strlen(str2);
        //printf("%s\n",str1);
        //kmp();
        x1=get_min()+1;
        x2=get_max()+1;
        makeNext();
    }
    return 0;
}

/*
Test case #1
2 2
3 3
*/

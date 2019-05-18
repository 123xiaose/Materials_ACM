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

int Next[maxn],ex[maxn],n,m,k,T;
map<char,char>mp;

char str1[maxn],str2[maxn],c[maxn];

void getnext(char *str)
{
    int i=0,j,pos=1,len=strlen(str);
    Next[0]=len;
    while(str[i]==str[i+1] && i+1<len)i++;
    Next[1]=i;
    for(i=2;i<len;i++)
    {
        if(Next[i-pos]+i<Next[pos]+pos)Next[i]=Next[i-pos];
        else
        {
            j=max(0,Next[pos]+pos-i);
            while(str[j]==str[j+1] && j+i<len)j++;
            Next[i]=j;
            pos=i;
        }
    }
}

void exkmp(char *str1,char *str2)
{
    int i=0,j,pos,len1=strlen(str1),len2=strlen(str2);
    getnext(str2);
    while(str1[i]==str2[i]&& i<len1 && i<len2)i++;
    ex[0]=i;
    pos=0;
    for(i=1;i<len1;i++)
    {
        if(Next[i-pos]+i<ex[pos]+pos)ex[i]=Next[i-pos];
        else
        {
            j=max(ex[pos]+pos-i,0);
            while(i+j<len1 && j<len2 && str1[i+j]==str2[j])j++;
            ex[i]=j;
            pos=i;
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        memset(Next,0,sizeof(Next));
        memset(ex,0,sizeof(ex));
        memset(c,0,sizeof(c));
        scanf("%s%s",str1,str2);
        int len1=strlen(str1);
        int len2=strlen(str2);
        for(int i=0;i<len1;i++)mp[str1[i]]='a'+i;
        for(int i=0;i<len2;i++)c[i]=mp[str1[i]];
        c[len2]=0;
        exkmp(str1,c);
        int maxi=len1;
        for(int i=0;i<len1;i++)
        {
            if(i+ex[i]>=len1&&i>=ex[i])
             {
                 maxi=i;
                 break;
             }
        }
        for(int i=0;i<maxi;i++)printf("%c",str1[i]);
        for(int i=0;i<maxi;i++)printf("%c",mp[str1[i]]);
        printf("\n");
    }
    return 0;
}

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
const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------
const int Max=98;

char s[210],str[maxn];
int ans[20],total;
int n,m;
typedef struct TrieNode
{
    int flag;
    int num;
    TrieNode *next[Max];
}Trie;

Trie *root;

void init()
{
    for(int i=0;i<Max;i++)
    {
        root->next[i]=NULL;
    }
    root->flag=0;
    root->num=0;
    total=0;
}

void insertTrie(char str[],int v)
{
    int len=strlen(str);
    Trie *p,*q;
    p=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-31;
        if(p->next[id]==NULL)
        {
            q=(Trie *)malloc(sizeof(Trie));
            //q=new Trie;
            memset(q,0,sizeof(Trie));
            p->next[id]=q;
            p=p->next[id];
        }
        else
        {
            p=p->next[id];
        }
    }
    p->num=v;
    p->flag=1;
}

void findTrie(char str[],int v)
{
    Trie *p,*q;
    p=root;
    int len=strlen(str);
    int i=0,j=0,cnt=0;
    for(i=0;i<len;i++)
    {
        q=root;
        for(j=i;j<len;j++)
        {
            int id2=str[j]-31;
            if(q->next[id2])
            {
                //if(q->flag)ans[cnt++]=q->num;
                q=q->next[id2];
                if(q->flag)ans[cnt++]=q->num;
            }
            else
                break;
        }
    }
    if(cnt!=0)
    {
        printf("web %d: ",v);
        sort(ans,ans+cnt);
        for(int k=0;k<cnt-1;k++)printf("%d ",ans[k]);
        printf("%d\n",ans[cnt-1]);
        total++;
    }
}

void del(Trie *root)
{
    int i;
    for(i=0;i<Max;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}

int main()
{
    while(~scanf("%d",&n))
    {
        root=(Trie *)malloc(sizeof(Trie));
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            insertTrie(s,i);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",str);
            findTrie(str,i);
        }
        printf("total: %d\n",total);
        del(root);
    }
    return 0;
}

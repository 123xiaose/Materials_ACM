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
const int maxn=1e4+5;
const int maxm=100;
const int INF=0x3f3f3f3f;

using namespace std;

//---------------------------------------------
const int maxLen=505;

int n, m, da[maxLen];
char s[maxn];
bool used[maxLen];
struct node {
    node *next[maxm];
    node *fail;
    int cnt;
    void init() {
        cnt = 0;
        fail = NULL;
        for(int i = 0; i < maxm; i++) next[i] = NULL;
    }
}root;
queue<node *>Q;

struct Aho_Corasick_Automation
{
    node *root;
    int tot, ans;
    void init() {
        root = new node;
        root->init();
        ans = 0; tot = 0;
    }
    void Insert(char *st)
    {
        node *p = root;
        for(int i = 0; st[i]; i++)
            {
            int pos = st[i] - ' ';
            if(!p->next[pos])
            {
                p->next[pos] = new node;
                p->next[pos]->init();
            }
            p = p->next[pos];
        }
        p->cnt = ++tot;
    }
    void getFail()
    {
        node *p, *fa, *son;
        Q.push(root);
        while(!Q.empty()) {
            fa = Q.front(); Q.pop();
            for(int i = 0; i < maxm; i++) {
                son = fa->next[i];
                if(!son) continue;
                if(fa == root) son->fail = root;
                else {
                    p = fa->fail;
                    while(p != root && !p->next[i]) p = p->fail;
                    p = p->next[i];
                    if(!p) son->fail = root;
                    else son->fail = p;
                }
                Q.push(son);
            }
        }
    }
    void Find(int ord, char *st)
    {
        int sze = 0;
        memset(used, 0, sizeof(used));
        node *p, *temp;
        p = root;
        for(int i = 0; st[i]; i++) {
            int pos = st[i] - ' ';
            while(p != root && !p->next[pos]) p = p->fail;
            p = p->next[pos];
            if(!p) p = root;
            temp = p;
            while(temp != root)
            {
                if(temp->cnt && !used[temp->cnt])
                {
                    da[++sze] = temp->cnt;
                    used[temp->cnt] = true;
                    temp = temp->fail;
                }
                else break;
            }
        }
        if(sze) ans++;
        else return;
        sort(da + 1, da + sze + 1);
        printf("web %d: ", ord);
        for(int i = 1; i < sze; i++) printf("%d ", da[i]); printf("%d\n", da[sze]);
    }
    int getAns() {return ans;}
}AC;

int main()
{
    AC.init();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        AC.Insert(s);
    }
    AC.getFail();
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", s);
        AC.Find(i, s);
    }
    printf("total: %d\n", AC.getAns());
    return 0;
}

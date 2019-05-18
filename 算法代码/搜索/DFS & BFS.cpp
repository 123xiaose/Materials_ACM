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
const int maxn=105;

using namespace std;


//-----------------------------

char str[1005][1005];
int N,M,cnt;

void DFS(int x,int y)
{
    str[x][y]='.';
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int nx=x+i,ny=y+j;
            if( 0<=nx && nx<N && 0<=ny && ny<M && str[nx][ny]=='W' )DFS(nx,ny);
        }
    }
}

int main()
{
    //In();Out();
    while(~scanf("%d%d",&N,&M))
    {
        cnt=0;
        for(int i=0;i<N;i++)
        {
            getchar();
            for(int j=0;j<M;j++)
            {
                scanf("%c",&str[i][j]);
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(str[i][j]=='W')
                {
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
//https://github.com/wangkuiwu/datastructs_and_algorithm/blob/master/source/graph/iterator/udg/cplus/MatrixUDG.cpp


/*
class MatrixUDG
{
private:
    int mVexs[maxn];
    int mVexNum;
    int mEdgNum;
    int mMatrix[maxn][maxn];

public:
    MatrixUDG();
    MatrixUDG(char vexs[],int vlen,char edges[][2],int elen);
    ~MatrixUDG()
    {

    }
    void DFS();
    void BFS();
    void print();
    char readchar();
    int getPos(char ch);
    int firstVertex(int v);
    int nextVertex(int v,int w);
    void DFS(int i,int *visited);
};

MatrixUDG::MatrixUDG()
{
    char c1,c2;
    int i,p1,p2;
    cout<<"input vertex number: ";
    cin>>mVexNum;
    cout<<"input edge number: ";
    cin>>mEdgNum;
    for(i=0;i<mVexNum;i++)
    {
        cout<<"vertex("<<i<<"):";
        mVexs[i]=readchar();
    }
    for(int i=0;i<mEdgNum;i++)
    {
        cout<<"edge("<<i<<"):";
        c1=readchar();
        c2=readchar();
        p1=getPos(c1);
        p2=getPos(c2);
        mMatrix[p1][p2]=1;
        mMatrix[p2][p1]=1;
    }
}

MatrixUDG::MatrixUDG(char vexs[], int vlen, char edges[][2], int elen)
{
    int i,p1,p2;
    mVexNum=vlen;
    mEdgNum=elen;
    for(i=0;i<mVexNum;i++)
    {
        mVexs[i]=vexs[i];
    }
    for (i = 0; i < mEdgNum; i++)
    {
        p1 = getPos(edges[i][0]);
        p2 = getPos(edges[i][1]);
        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

int MatrixUDG::getPos(char ch)
{
    int i;
    for(i=0;i<mVexNum;i++)
    {
        if(mVexs[i]==ch)
            return 1;
    }
    return -1;
}

char MatrixUDG::readchar()
{
    char ch;
    do
    {
        cin>>ch;
    }while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));
    return ch;
}

int MatrixUDG::firstVertex(int v)
{
    int i;
    for(i=0;i<mVexNum;i++)
    {
        if(mMatrix[v][i]==1)
            return i;
    }
    return -1;
}

int MatrixUDG::nextVertex(int v, int w)
{
    int i;
    for (i = w + 1; i < mVexNum; i++)
        if (mMatrix[v][i] == 1)
            return i;
    return -1;
}

void MatrixUDG::DFS(int i,int *visited)
{
    int w;
    visited[i]=1;
    cout<<mVexs[i]<<" ";
    for(w=firstVertex(i);w>=0;w=nextVertex(i,w))
    {
        if(!visited[w])
        {
            DFS(w,visited);
        }
    }
}

void MatrixUDG::DFS()
{
    int i;
    int visited[maxn];
    for(i=0;i<mVexNum;i++)
    {
        visited[i]=0;
    }
    cout<<"DFS: ";
    for(i=0;i<mVexNum;i++)
    {
        if(!visited[i])
        {
            DFS(i,visited);
        }
    }
    cout<<endl;
}

void MatrixUDG::print()
{
    int i,j;
    cout << "Martix Graph:" << endl;
    for (i = 0; i < mVexNum; i++)
    {
        for (j = 0; j < mVexNum; j++)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    MatrixUDG* pG;
    pG = new MatrixUDG(vexs, vlen, edges, elen);

    pG->print();
    //pG->DFS();
    //pG->BFS();
    return 0;
}


*/

#include<cstdio>
#include<cstring>
#include<algorithm>
const int mod=1e9+7;
typedef long long ll;
struct mat
{
    ll str[2][2];
};
mat mat_mul(mat x,mat y,int mol)
{
    mat result;
    memset(result.str,0,sizeof(result.str));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                result.str[i][j]=(result.str[i][j]+x.str[i][k]*y.str[k][j])%mol;
            }
        }
    }
    return result;
}
void mat_pow(int n,int p)
{
    mat c,res;
    c.str[0][0]=c.str[0][1]=c.str[1][0]=1;
    c.str[1][1]=0;
    memset(res.str,0,sizeof(res.str));
    for(int i=0;i<2;i++) res.str[i][i]=1;
    while(n)
    {
        if(n%2==1) res=mat_mul(res,c,p);
        c=mat_mul(c,c,p);
        n=n>>1;
    }
    printf("%d\n",res.str[0][1]);
}
int gcd(int x,int y)
{
    int temp;
    while(temp=x%y)
    {
        x=y;
        y=temp;
    }
    return y;
}

using namespace std;

int main()
{
    int T,m,n,p,t;
    while(~scanf("%d",&n))
    {
       mat_pow(n,mod);
    }
    return 0;
}

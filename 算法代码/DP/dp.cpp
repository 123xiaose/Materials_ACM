/*#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int p[11]={0,1,5,8,9,10,17,17,20,24,30},r[11];
    int n,sum=0,ans=0;
    while(scanf("%d",&n) == 1)
    {
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++)
        {
            ans=p[i];
            for(int j=0;j<i;j++)
            {
                sum=r[j]+r[i-j];
                if(sum>ans)
                {
                    ans=sum;
                }
            }
            r[i]=ans;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",r[i]);
        }
    }
    return 0;
}*/

/*#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n=6,t[6]={2,3,4,1,3,1},r[5]={4,5,3,2,2};
    int ans[7];
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        if(i==0)ans[0]=0;
        else if(i==1)
        {
            ans[1]=t[0];
        }
        else
        {
           ans[i]=min( (ans[i-1]+t[i-1]),(ans[i-2]+r[i-2]) );
        }
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}*/

/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int main()
{
    long long f[25],ans,temp,T,N,str[55];                  ÅÀÂ¥ÌÝ
    memset(f,0,sizeof(f));
    f[0]=1;f[1]=2;f[2]=4;
    for(int i=3;i<20;i++)
    {
        f[i]=( (f[i-1]+f[i-2]+f[i-3] )%10007 );
    }
    scanf("%lld",&T);
    while(T--)
    {
        ans=1;
        memset(str,0,sizeof(str));
        scanf("%lld",&N);
        for(int i=0;i<(N-1);i++)
        {
            scanf("%lld",&str[i]);
            temp=str[i];
            ans=((ans%10007)*(f[temp-1]%10007 ))%10007;
        }
        printf("%lld\n",ans);
    }
    return 0;
}*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define LEN 100005
using namespace std;
int main()
{
    int str[LEN],result[LEN],T,N,K,ans;
    while(scanf("%d",&T) == 1)
    {
        while(T--)
        {
            memset(str,0,sizeof(str));
            memset(result,0,sizeof(result));
            scanf("%d%d",&N,&K);
            for(int i=1;i<=N;i++)
            {
                scanf("%d",&str[i]);
            }
            result[1]=str[1];
            for(int i=2;i<=(K+1);i++)
            {
                result[i]=max(result[i-1],str[i]);
            }
            for(int i=(K+2);i<=N;i++)
            {
                result[i]=max(result[i-1],(str[i]+result[i-K-1]) );
            }
            printf("%d\n",result[N]);
        }
    }
    return 0;
}

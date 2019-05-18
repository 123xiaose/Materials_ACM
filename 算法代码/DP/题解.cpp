    #include <iostream>
    #include <cstdio>
    #include <string>
    #include <string.h>
    using namespace std;
    #define M 1010
    char str[M][M];
    int n,m,ans;
    int height[M][M],l[M],r[M];
    int max(int a,int b){
      return a>b?a:b;
    }
    void dp(){
      for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
          l[j]=j;r[j]=j;
        }
        height[i][0]=-1;height[i][m+1]=-1;
        for(int j=1;j<=m;++j){
          while(height[i][j]<=height[i][l[j]-1]){
             l[j]=l[l[j]-1];
          }
        }
        for(int j=m;j>=1;--j){
          while(height[i][j]<=height[i][r[j]+1])
             r[j]=r[r[j]+1];
        }
        for(int j=1;j<=m;++j){
           ans=max(ans,(r[j]-l[j]+1)*height[i][j]);
        }
      }
    }
    int main(){
      int numcase;
      scanf("%d",&numcase);
      while(numcase--){
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;++i){
           for(int j=1;j<=m;++j)
              cin>>str[i][j];
         }
         memset(height,0,sizeof(height));
         for(int i=1;i<=n;++i){
           for(int j=1;j<=m;++j){
             if(str[i][j]=='F')
                height[i][j]=height[i-1][j]+1;
           }
         }
         ans=0;
         dp();
         printf("%d\n",ans*3);
      }
      return 0;
    }

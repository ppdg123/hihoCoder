#include <stdio.h>
#define MINV(a,b) (a>b?b:a)

int data[1005][1005];
int dp[1005][1005];

int N;

int count(int v ,int t)
{
    int c = 0;
    while(v%t==0) {v/=t; c++;}
    return c;
}

int solve(int target)
{
   int i,j;
   dp[0][0] = count(data[0][0],target);
   for(i=1;i<N;i++)
   {
      if(data[0][i]>0)
      {
          dp[0][i] = dp[0][i-1]>=0?dp[0][i-1]+count(data[0][i],target):-1;
      }else dp[0][i] = -1;
      if(data[i][0]>0)
      {
          dp[i][0] = dp[i-1][0]>=0?dp[i-1][0]+count(data[i][0],target):-1;
      }else dp[i][0] = -1;
   }
   for(i=1;i<N;i++)
   {
       for(j=1;j<N;j++)
       {
           if(data[i][j]>0)
           {
               if(dp[i-1][j]==-1&&dp[i][j-1]==-1) dp[i][j] = -1;
               if(dp[i-1][j]==-1&&dp[i][j-1]!=-1) dp[i][j] = dp[i][j-1]+count(data[i][j],target);
               if(dp[i-1][j]!=-1&&dp[i][j-1]==-1) dp[i][j] = dp[i-1][j]+count(data[i][j],target);
               if(dp[i-1][j]!=-1&&dp[i][j-1]!=-1) dp[i][j] = MINV(dp[i][j-1],dp[i-1][j])+count(data[i][j],target);
           }
           else dp[i][j] = -1;
       }
   }
   return dp[N-1][N-1];
}

int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    while(EOF != scanf("%d",&N))
    {
        for(i=0;i<N;i++)
         for(j=0;j<N;j++)
          scanf("%d",&data[i][j]);
        i = solve(2);
        j = solve(5);
        printf("%d\n",MINV(i,j));
    }
    return 0;
}
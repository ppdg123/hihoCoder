#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV(a,b) (a>b?a:b)
    int c[505],v[505];
    int dp[505][10001];
int main()
{
    int i,j,N,M;

    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%d%d",&c[i],&v[i]);
    }
    memset(dp,0,sizeof dp);
    for(i=c[0];i<=M;i++)
    {
        dp[0][i] = v[0];
    }
    for(i=1;i<N;i++)
    {
        for(j=0;j<=M;j++)
        {
            if(c[i]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = MAXV(dp[i-1][j-c[i]]+v[i],dp[i-1][j]);
            }
        }
    }
    printf("%d\n",dp[N-1][M]);
    return 0;
}
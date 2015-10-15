#include <stdio.h>
#include <string.h>
int dp[1005][1005];
char str[1005];


int main()
{
    int T,i,j,k,len,s;
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(s=0;s<T;s++)
    {
        memset(dp,0,sizeof dp);
        scanf("%s",str);
        len = strlen(str);
        
        for(k=0;k<len;k++)
        {
            for(i=1;i<=len-k;i++)
            {
                j = i+k;
                if(str[i-1]==str[j-1])
                {
                    dp[i][j] = (dp[i][j-1]+dp[i+1][j]+1)%100007;
                }
                else
                {
                    dp[i][j] = ((dp[i][j-1]+dp[i+1][j] - dp[i+1][j-1])%100007+100007)%100007;//中间取MOD可能为负数
                }
            }
        }
        printf("Case #%d: %d\n",s+1,dp[1][len]);
    }
    return 0;
}
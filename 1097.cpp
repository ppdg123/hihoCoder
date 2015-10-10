#include <stdio.h>

int main()
{
    int N;
    int a[1005][1005],i,j,dis[1005],vis[1005],tmp,idx,res;
    while(EOF != scanf("%d",&N))
    {
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                scanf("%d",&a[i][j]);
        vis[0] =1;
        for(i=0;i<N;i++)
        {
            dis[i] = a[0][i];
        }
        res = 0;
        for(i=0;i<(N-1);i++)
        {
            tmp = 99999999;
            for(j=0;j<N;j++)
            {
                if(!vis[j])
                {
                    if(tmp>dis[j])
                    {
                        tmp = dis[j];
                        idx = j;
                    }
                }
            }
            res += tmp;
            vis[idx] = 1;
            for(j=0;j<N;j++)
            {
                if(!vis[j])
                {
                    if(dis[j]>a[j][idx])
                    {
                        dis[j] = a[j][idx];
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
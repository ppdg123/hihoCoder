#include <stdio.h>
#include <string.h>
int dis[105][105];

int main()
{
    int n,m;
    int i,j,k,a,b,c;
    freopen("in.txt","r",stdin);
    while(EOF != scanf("%d%d",&n,&m))
    {
        memset(dis,0,sizeof dis);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            if(dis[a][b]==0||dis[a][b]>c)
            {
                dis[a][b] = c;
                dis[b][a] = c;
            }
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<i;j++)
                {
                    if(k==i||k==j) continue;
                    if(dis[i][k]!=0&&dis[k][j]!=0)
                    {
                        if(dis[i][j]==0||(dis[i][k]+dis[k][j])<dis[i][j])
                        {
                            dis[i][j] = (dis[i][k]+dis[k][j]);
                            dis[j][i] = dis[i][j];
                        }
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<(n-1);j++)
            {
                printf("%d ",dis[i][j]);
            }
            printf("%d\n",dis[i][n-1]);
        }
    }
    return 0;
}
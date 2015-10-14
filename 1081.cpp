#include <stdio.h>
#include <string.h>
int n,m,s,t;
int dis[1001][1001];
int vis[1001],sdis[1001];

int main()
{
    int i,j,a,b,c,cnt,minv,mini;
    //freopen("in.txt","r",stdin);
    while(EOF != scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        memset(dis,0,sizeof dis);
        memset(sdis,0,sizeof sdis);
        memset(vis,0,sizeof vis);
        cnt = 1;
        s--;t--;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            if(dis[a][b]==0||dis[a][b]>c){
                dis[a][b] = c;
                dis[b][a] = c;
            }
        }
        
        vis[s] = 1;
        for(i=0;i<n;i++)
        {
            if(!vis[i]&&dis[s][i]>0)
            {
                sdis[i] = dis[s][i];
            }
        }
        while(cnt < n)
        {
            minv = 1e9;
            for(i=0;i<n;i++)
            {
                if(sdis[i]>0&&!vis[i])
                {
                    if(sdis[i]<minv)
                    {
                        minv = sdis[i];mini = i;
                    }
                }
            }
            vis[mini] = 1;
            for(i=0;i<n;i++)
            {
                if(!vis[i]&&dis[mini][i]>0)
                {
                    if((dis[mini][i]+sdis[mini])<sdis[i]||sdis[i]==0)
                    {
                        sdis[i] = (dis[mini][i]+sdis[mini]);
                    }
                }
            }
            cnt ++;
        }
        printf("%d\n",sdis[t]);
    }
    return 0;
}
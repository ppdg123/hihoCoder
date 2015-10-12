#include <stdio.h>
int n,m;
char a[205][205],p[4][4];

void rota()
{
    int tmp;
    tmp = p[0][0]; p[0][0]=p[0][2];p[0][2] = p[2][2];p[2][2]=p[2][0];p[2][0] = tmp;
    tmp = p[0][1]; p[0][1]=p[1][2];p[1][2] = p[2][1];p[2][1]=p[1][0];p[1][0] = tmp;
}

int check(int y, int x)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[y+i][x+j]!=p[i][j]) return 0;
        }
    }
    return 1;
}

void solve()
{
    int i,j,k,flag;
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<m-2;j++)
        {
            flag = 0;
            for(k=0;k<4;k++)
            {
                flag = check(i,j);
                if(flag)
                {
                    printf("%d %d\n",i+2,j+2);
                    break;
                }
                rota();
            }
        }
    }
}

int main()
{
    int i,j,y,x;
    while(EOF != scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        scanf("%s",p[0]);
        scanf("%s",p[1]);
        scanf("%s",p[2]);
        solve();
    }
    return 0;
}
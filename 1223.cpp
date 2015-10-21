#include <stdio.h>
#include <string.h>
int v[2006];
char str1[10],str2[10];
int d,n,i;
// x>2 x<3
int main()
{
    freopen("in.txt","r",stdin);
    while(EOF != scanf("%d",&n))
    {
        memset(v,0,sizeof v);
        while(n--)
        {
            scanf("%s%s%d",str1,str2,&d);
            d <<= 1;
            if(0==strcmp("=",str2))
            {
                v[d+1] ++;
            }
            if(0==strcmp("<",str2))
            {
                for(i=0;i<(d+1);i++)
                {
                    v[i]++;
                }
            }
            if(0==strcmp("<=",str2))
            {
                for(i=0;i<=(d+1);i++)
                {
                    v[i]++;
                }
            }
            if(0==strcmp(">",str2))
            {
                for(i=(d+2);i<=2005;i++)
                {
                    v[i]++;
                }
            }
            if(0==strcmp(">=",str2))
            {
                for(i=(d+1);i<=2005;i++)
                {
                    v[i]++;
                }
            }
        }
        int ans = 0;
        for(i=0;i<=2005;i++)
        {
            if(ans < v[i]) ans = v[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
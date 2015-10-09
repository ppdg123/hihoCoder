#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calf(char * str, int * f)
{
    f[0] = -1;
    int i,j;
    i = 0;
    j = -1;
    while(str[i]!='\0')
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            f[i] = j;
        }
        else
        {
            j = f[j];
        }
    }
}

int cmp(char * s, char * p, int * f)
{
    int i,j,cnt = 0;
    i = 0,j=0;
    while(s[i]!='\0')
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
            if(p[j]=='\0')
            {
                i--;
                j = f[j-1];
                cnt ++;
            }
        }
        else
        {
            j = f[j];
        }
    }
    return cnt;
}

int main()
{
    int N,f[10005],res;
    char s[1000005],p[10005];
    while(EOF != scanf("%d",&N))
    {
        scanf("%s%s",p,s);
        calf(p,f);
        res = cmp(s,p,f);
        printf("%d\n",res);
    }
    return 0;
}
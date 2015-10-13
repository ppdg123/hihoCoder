#include <stdio.h>
#include <string.h>

int del(char * str,int len)
{
    int vis[105];
    int flag = 0,f=1;
    int i=0,j,cnt=0;
    memset(vis,0,sizeof vis);
    while(f){
        f=0;
        i=0;
        while(i<len)
        {
            while(vis[i]) i++;
            j=i+1;
            flag = 0;
            while(j<len&&(str[j]==str[i]||vis[j]))
            {
                if(str[j]==str[i]&&!vis[j])
                {
                    flag = 1;
                    vis[j] =1;
                    f = 1;
                    cnt ++;
                }
                j++;
            }
            if(flag) {vis[i] = 1;cnt ++;}
            i = j;
        }
    }
    return cnt;
}
int solve(char * str)
{
    int len = strlen(str);
    int i,j,k;
    char s[105];
    int cnt = 0;
    for(i=0;i<len;i++)
    {
        for(k='A';k<='C';k++){
            snprintf(s,i+1,"%s",str);
            //s[i]='\0';
            s[i] = k;
            sprintf(&s[i+1],"%s",&str[i]);
            s[len+1] ='\0';
            //printf("%s\n",s);
            j = del(s,len+1);
            if(j>cnt) cnt = j;
        }
    }
    return cnt;
}

int main()
{
    int N;
    char str[105];
    while(EOF != scanf("%d",&N))
    {
        while(N--)
        {
            scanf("%s",str);
            printf("%d\n",solve(str));
        }
    }
    return 0;
}
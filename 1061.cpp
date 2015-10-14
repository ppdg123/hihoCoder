#include <stdio.h>
#include <string.h>
#define MINV(a,b) (a>b?b:a)
int n[20000000];
char ac[20000000];

char input[20000000];
int main()
{
    int T,N,cnt,a,flag,i,j;
    char tmp,t; 
    while(EOF != scanf("%d",&T))
    {
      while(T--){
        scanf("%d",&N);
        scanf("%s",input);
        memset(n,0,sizeof(n));
        n[0] = 1;
        ac[0] = input[0];
        cnt = 0;
        for(j=1;j<N;j++)
        {
            if(input[j-1]==input[j])
            {
                n[cnt]++;
            }
            else
            {
                cnt++;
                n[cnt]++;
                ac[cnt] = input[j];
            }
        }
        flag = 0;
        for(i=0;i<cnt-1;i++)
        {
            a = n[i+1];
            if(n[i]>=a&&n[i+2]>=a&&ac[i+1]==(ac[i]+1)&&ac[i+2]==(ac[i+1]+1))
            {
                flag = 1;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    }
    return 0;
}
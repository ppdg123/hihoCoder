#include <stdio.h>

int main()
{
    int a[105],b[105];
    int N,i,pre,res,tmp,M,len,T;
    while(EOF != scanf("%d",&T))
    {
      while(T--)
      {
        scanf("%d%d",&N,&M);
        pre = 0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i]-pre-1;
            pre = a[i];
        }
        b[i] = 100-pre;
        res = 0;
        tmp = b[0];
        len = 1;
        i = 1;
        while(i<(N+1))
        {
            if(M>0)
            {
                tmp += (b[i]+1);
                M--;
                len ++;
                i++;
            }
            else
            {
                if(tmp > res) res = tmp;
                tmp -= (b[i-len]+1);
                len --;
                M++;
            }
        }
         if(tmp > res) res = tmp;
        printf("%d\n",res);
      }
    }
    return 0;
}
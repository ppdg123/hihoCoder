#include <stdio.h>

int main()
{
    int P,Q;
    int p[10000],q[10000],cntp,cntq;
    int i,j;
    scanf("%d%d",&P,&Q);
    cntp = 0; cntq = 0;
    for(i=1;i<=P;i++)
    {
        if(!(P%i)) p[cntp++] = i;
    }
    for(i=1;i<=Q;i++)
    {
        if(!(Q%i)) q[cntq++] = i;
    }
    for(i=0;i<cntp;i++)
      for(j=0;j<cntq;j++)
        printf("%d %d\n",p[i],q[j]);
    return 0;
}
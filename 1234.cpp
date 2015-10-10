#include <stdio.h>
#include <math.h>
#define EPS 1e-8

int main()
{
    int T;
    double t,a,b,c;
    int cnt;
    while(EOF != scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%lf",&t);
            a = 0;
            cnt = 0;
            b = 0.5;
            while(t>=a)
            {
                a += b/2.0;
                b /= 2.0;
                cnt += 4;
            }
            if(a==t)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}
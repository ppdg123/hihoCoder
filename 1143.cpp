#include <stdio.h>

int main()
{
    int n,i,a,b,c;
    while(EOF != scanf("%d",&n))
    {
        a = 1;
        b = 2;
        for(i=2;i<n;i++)
        {
            c = (a+b)%19999997;
            a = b;
            b = c;
        }
        if(n==1) printf("1\n");
        if(n==2) printf("2\n");
        if(n>2) printf("%d\n",c);
    }
    return 0;
}
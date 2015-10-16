#include <stdio.h>

int a,b,n,i;

int main()
{
    scanf("%d%d",&n,&a);
    for(i=1;i<n;i++){
       scanf("%d",&b);
       a ^= b;
    }
    if(!a) printf("Bob\n");
    else printf("Alice\n");
    return 0;
}
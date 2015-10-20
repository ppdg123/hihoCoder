#include <stdio.h>

int main()
{
    char ch;
    int space=0,first=0,prespace=1;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(EOF != scanf("%c",&ch))
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            if(space&&!prespace) printf(" ");
            if(!first)
            {
                first = !first;
                if(ch>='a'&&ch<='z') printf("%c",ch-'a'+'A');
                else printf("%c",ch);
            }
            else
            {
                if(ch>='A'&&ch<='Z') printf("%c",ch-'A'+'a');
                else printf("%c",ch);
            }
            space = 0;
            prespace = 0;
        }
        if(ch==' ')
        {
            space = 1;
        }
        if(ch=='.'||ch==',') 
        {
            printf("%c",ch);
            space = 1;
            if(ch=='.') first=0;
        }
        if(ch=='\n')
        {
            printf("\n");
            prespace = 1;
            first = 0;
            space = 0;
        }
    }
    return 0;
}
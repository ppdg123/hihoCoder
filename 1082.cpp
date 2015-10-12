#include <stdio.h>
#include <string.h>

int main()
{
    char str[2005],lstr[2005];
    while(NULL != gets(str))
    {
        int len = strlen(str);
        int i;
        for(i=0;i<len;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                lstr[i] = 'a'+str[i]-'A';
            }
            else lstr[i] = str[i];
        }
        lstr[i] = '\0';
        for(i=0;i<len;)
        {
            if(0==strncmp(&lstr[i],"marshtomp",9))
            {
                printf("fjxmlhx");
                i+=9;
            }
            else
            {
                printf("%c",str[i]);
                i++;
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int val[3],cur[3];
    char str[20005];
    scanf("%d%d%d",&val[0],&val[1],&val[2]);
    sort(val,val+3);
    scanf("%s",str);
    int len = strlen(str);
    int cnt = 0;
    int pcnt[200],tmp,i;
    memset(pcnt,0,sizeof pcnt);
    i = 0;
    int maxv = 0;
    while(i<len)
    {
        pcnt[str[i]]++;
        tmp =  pcnt['R']+pcnt['B']+pcnt['Y'];
        if(tmp>cnt) cnt = tmp;
        cur[0] = abs(pcnt['R']-pcnt['B']);
        cur[1] = abs(pcnt['R']-pcnt['Y']);
        cur[2] = abs(pcnt['B']-pcnt['Y']);
        sort(cur,cur+3);
        if(maxv<cnt) maxv=cnt;
        if(cur[0]==val[0]&&cur[1]==val[1]&&cur[2]==val[2])
        {
            pcnt['R']=0,pcnt['B']=0,pcnt['Y']=0;
        }
        i++;
    }
    printf("%d\n",maxv);
    return 0;
}
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node 
{
    int a,b,dis;
};

int getFather(int * f, int i)
{
    if(i!=f[i])
    {
        f[i] = getFather(f,f[i]);
    }
    return f[i];
}

int cmp(struct node  a, struct node b)
{
    return a.dis < b.dis;
}

struct node dis[1000006];
int N,M,i,j,father[100005],f1,f2,tmp,idx1,idx2,res;
int main()
{
    
    while(EOF != scanf("%d%d",&N,&M))
    {
        for(i=0;i<M;i++) scanf("%d%d%d",&dis[i].a,&dis[i].b,&dis[i].dis);
        for(i=0;i<N;i++) father[i] = i;
        res = 0;
        j = 0;
        sort(dis,dis+M,cmp);
        for(i=1;i<N;i++)
        {
            while(1)
            {
                f1 = getFather(father,dis[j].a);
                f2 = getFather(father,dis[j].b);
                if(f1!=f2)
                {
                    res += dis[j].dis;
                    if(f1<=f2) father[f2] = f1;
                    else father[f1] = f2;
                    j++;
                    break;
                }
                j++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
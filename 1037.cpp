#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXV(a,b) ((a)>(b)?(a):(b))

int main()
{
    int N;
    int nums[205],i,j,val,res;
//    freopen("in.txt","r",stdin);
    while(EOF != scanf("%d",&N))
    {
        memset(nums,0,sizeof nums);
        res = 0;
        for(i=1;i<=N;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                scanf("%d",&val);
                if(j>0)
                {
                    nums[j] = MAXV(nums[j-1],nums[j])+val;
                }
                else
                {
                    nums[j] = nums[j]+val;
                }
                if(res < nums[j]) res = nums[j];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
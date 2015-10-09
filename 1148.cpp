#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
char months[12][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

bool is_year(int n)
{
    return (n%4==0 && n%100!=0) || (n%400==0);
}

int calc(int year,int mon,int day)
{
    int sum = year/4+year/400-year/100;
    if(is_year(year) && (mon < 2 || mon == 2 && day <29))
        sum--;
    return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++)
    {
        char name1[20],name2[20];
        int day1,year1,mon1,day2,year2,mon2;
        scanf("%s %d,%d",name1,&day1,&year1);
        scanf("%s %d,%d",name2,&day2,&year2);
        for(int i = 0; i < 12; i++)
        {
            if(strcmp(name1,months[i]) == 0)
            {
                mon1 = i+1;
            }
            if(strcmp(name2,months[i]) == 0)
            {
                mon2 = i+1;
            }
        }
        int num1 = calc(year1,mon1,day1);
        int num2 = calc(year2,mon2,day2);
        int res = num2-num1;
        if(is_year(year1) && mon1 == 2 && day1 == 29) res++;
        printf("Case #%d: %d\n",t,res);
    }
}

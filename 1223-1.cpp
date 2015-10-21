#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;
typedef long long LL;
#define MAXN 55
string s,op[MAXN];
int n,num[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    while(cin >> n)
    {
        for(int i = 0;i < n;i++)
        {
            cin >> s >> op[i] >> num[i];
            //num[i] <<= 1;
        }
        int maxn = 1;
        for(int x = -1;x <= 1003;x++)
        {
            int tem = 0;
            for(int k = 0;k < n;k++)
            {
                if(op[k] == "=" && x == num[k])tem++;
                else if(op[k] == "<=" && x <= num[k])tem++;
                else if(op[k] == ">=" && x >= num[k])tem++;
                else if(op[k] == "<" && x < num[k])tem++;
                else if(op[k] == ">" && x > num[k])tem++;
            }
            maxn = max(maxn,tem);
        }
        cout << maxn << endl;
    }
    return 0;
}
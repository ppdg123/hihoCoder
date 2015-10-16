#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;
 
int main()
{
    string s, cur;
    set<string>t;
    cin>>s;
    int len=s.size();
    int i, j, k;
    int a[26];
    int f[101];
    i = 0;    j = 1;    k = 1;
    memset(f,0,sizeof f);
    while(k<100)
    {
       f[k] = 1;
       i = j;
       j = k;
       k = i+j;
    }
    for(i=0; i<len; i++)
    {
        for(j=1; i+j<=len; j++)
        {
            cur = s.substr(i, j);
            int length=cur.size();
            memset(a,0,sizeof(a));
            int cnt = 0;
            for(k=0; k<length; k++)
            {
                if(!a[cur[k]-97]) {cnt++;a[cur[k]-97]=1;}
            }
            if(f[cnt]) t.insert(cur);
        }
    }
    set<string>::iterator it=t.begin();
    while(it!=t.end())
    {
        cout<<*it<<endl;
        it++;
    }
    return 0;
}
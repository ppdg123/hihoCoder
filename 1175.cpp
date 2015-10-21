#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int in[100005],cnt[100005];
vector<int> v[100005], zeroin;

int main()
{
    int m,n,k,i,j,t,u,ans;
    //freopen("in.txt","r",stdin);
    while(cin>>n>>m>>k)
    {
        ans = 0;
        memset(in,0,sizeof in);
        memset(cnt,0,sizeof cnt);
        memset(v,0,sizeof v);
        zeroin.clear();
        for(i=0;i<k;i++)
        {
            cin>>t;
            cnt[t] ++;
        }
        for(i=0;i<m;i++)
        {
            cin>>t>>u;
            v[t].push_back(u);
            in[u] ++;
        }
        for(i=1;i<=n;i++)
        {
            if(in[i]==0)
            {
                zeroin.push_back(i);
            }
        }
        for(i=0;i<n;i++)
        {
            t = zeroin.back();
            zeroin.pop_back();
            for(j=0;j<v[t].size();j++)
            {
                    cnt[v[t][j]] += cnt[t];
                    cnt[v[t][j]] = cnt[v[t][j]]%142857;
                    in[v[t][j]] --;
                    if(in[v[t][j]]==0) zeroin.push_back(v[t][j]);
            }
            ans += cnt[t];
            ans = ans%142857;
        }
        printf("%d\n",ans);
    }
    return 0;
}
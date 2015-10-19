#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
vector<int> m[10004];
int vis[10004],ans;
void DFS(int now,int pre)
{
    int i,len;
    if(!vis[now])
    {
        if(pre==1) vis[now] = 2;
        else vis[now] = 1;
    }
    else
    {
        return;
    }
    len = m[now].size();
    for(i=0;i<len;i++)
    {
        if(!vis[m[now][i]]) DFS(m[now][i],pre==1?2:1);
        else
        {
            if(vis[now]==vis[m[now][i]])
            {
                ans =  0;
            }
        }
    }
}
int main()
{
    int T,N,M,i,a,b,c;
    //freopen("in.txt","r",stdin);
    while(cin>>T)
    {
        while(T--)
        {
            cin>>N>>M;
            memset(vis,0,sizeof vis);
            memset(m,0,sizeof m);
            ans = 1;
            for(i=0;i<M;i++)
            {
                cin>>a>>b;
                m[a].push_back(b);
                m[b].push_back(a);
            }
            for(i=1;i<=N;i++)
            {
                if(!vis[i])
                {
                    DFS(i,1);
                }
            }
            if(ans) cout<<"Correct"<<endl;
            else cout<<"Wrong"<<endl;
        }
    }
    return 0;
}
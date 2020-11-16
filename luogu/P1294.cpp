#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,ans=0;
struct edge
{
    int to,val;
    edge(int a,int b):to(a),val(b){}
};
vector<edge> p[25];
bool vis[25];

void dfs(int x,int cnt)
{
    ans=max(ans,cnt);
    for(int i=0;i<(int)p[x].size();++i){
        if(!vis[p[x][i].to]){
            vis[p[x][i].to]=true;
            dfs(p[x][i].to,cnt+p[x][i].val);
            vis[p[x][i].to]=false;
        }
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        p[a].push_back(edge(b,c));
        p[b].push_back(edge(a,c));
    }
    for(int i=1;i<=n;++i){
        vis[i]=true;
        dfs(i,0);
        vis[i]=false;
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

int n,m,x,y,k;
int p[400005],del[400005],as[400005];
bool vis[400005];
vector<int> g[400005];

int fi(int x)
{
    if(p[x]==x)
        return x;
    else{
        p[x]=fi(p[x]);
        return p[x];
    }
}

void me(int x,int y)
{
    p[fi(x)]=fi(y);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        p[i]=i;
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    memset(vis,0,sizeof(vis));
    scanf("%d",&k);
    for(int i=1;i<=k;++i){
        scanf("%d",&del[i]);
        vis[del[i]]=true;
    }
    int tt=n-k;
    for(int i=0;i<=n-1;++i){
        if(vis[i])
            continue;
        for(int j=0;j<g[i].size();++j){
            if(vis[g[i][j]])
                continue;
            if(fi(i)!=fi(g[i][j])){
                tt--;
                me(i,g[i][j]);
            }
        }
    }
    as[k+1]=tt;
    for(int i=k;i>=1;--i){
        tt++;
        vis[del[i]]=false;
        for(int j=0;j<g[del[i]].size();++j){
            if(vis[g[del[i]][j]])
                continue;
            if(fi(del[i])!=fi(g[del[i]][j])){
                tt--;
                me(del[i],g[del[i]][j]);
            }
        }
        as[i]=tt;///
    }
    for(int i=1;i<=k+1;++i)
        printf("%d\n",as[i]);
    return 0;
}

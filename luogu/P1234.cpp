#include <bits/stdc++.h>
using namespace std;

int n,m;
char p[1005][1005];
int ans=0;
bool vis[1005][1005];

void dfs(int i,int j,int hcnt,int ecnt,int d)
{
    if(i<1||i>n||j<1||j>m||vis[i][j])
        return;
    if(p[i][j]!='h'&&p[i][j]!='e')
        return;
    if(hcnt>ecnt&&p[i][j]=='h')
        return;
    if(ecnt>=hcnt&&p[i][j]=='e')
        return;
    if(p[i][j]=='e')
        ecnt++;
    else if(p[i][j]=='h')
        hcnt++;
    if(hcnt==2&&ecnt==2){
        ans++;
        return;
    }
    vis[i][j]=true;
    if(d==0){
        dfs(i+1,j,hcnt,ecnt,1);
        dfs(i-1,j,hcnt,ecnt,2);
        dfs(i,j+1,hcnt,ecnt,3);
        dfs(i,j-1,hcnt,ecnt,4);
    }
    if(d==1)
        dfs(i+1,j,hcnt,ecnt,1);
    if(d==2)
        dfs(i-1,j,hcnt,ecnt,2);
    if(d==3)
        dfs(i,j+1,hcnt,ecnt,3);
    if(d==4)
        dfs(i,j-1,hcnt,ecnt,4);
    vis[i][j]=false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>p[i][j];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(p[i][j]=='h')
                dfs(i,j,0,0,0);
        }
    }
    cout<<ans;
    return 0;
}

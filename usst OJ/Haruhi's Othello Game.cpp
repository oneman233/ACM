#include <bits/stdc++.h>
using namespace std;

int t,n,r,x,y,ans;
int p[10005][10005];
bool vis[10005];

void init()
{
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    ans=-100;
}

void dfs(int x,int step)
{
    ans=max(ans,step);
    vis[x]=true;
    for(int i=1;i<=n;++i){
        if(p[i][x]==1&&!vis[i])
            dfs(i,step+1);
    }
    vis[x]=false;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>r;
        init();
        for(int i=0;i<n-1;++i){
            cin>>x>>y;
            p[x][y]=p[y][x]=1;
        }
        dfs(r,1);
        if(ans&1){
            if(ans==1)
                cout<<"Haruhi go first."<<endl;
            else
                cout<<"Haruhi go second."<<endl;
        }
        else
            cout<<"Haruhi go first."<<endl;
    }
    return 0;
}

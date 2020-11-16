#include <bits/stdc++.h>
using namespace std;
const int maxn=2000000;

int n,m,x,y;
char c[1005][1005];
int p[maxn];
bool vis[1005][1005];
int ans[maxn];

int h(int x,int y)
{
    return x+y*n;
}

int fi(int x)
{
    if(x!=p[x])
        p[x]=fi(p[x]);
    return p[x];
}

void me(int x,int y)
{
    int rx=fi(x);
    int ry=fi(y);
    if(rx!=ry)
        p[rx]=ry;
}

int dfs(int fi,int fj,int i,int j,char ch)
{
    if(i<1||i>n||j<1||j>n||c[i][j]!=ch||vis[i][j])
        return 0;
    vis[i][j]=1;
    ans[h(i,j)]+=dfs(fi,fj,i+1,j,'0'+'1'-ch);
    ans[h(i,j)]+=dfs(fi,fj,i-1,j,'0'+'1'-ch);
    ans[h(i,j)]+=dfs(fi,fj,i,j+1,'0'+'1'-ch);
    ans[h(i,j)]+=dfs(fi,fj,i,j-1,'0'+'1'-ch);
    me(h(i,j),h(fi,fj));
    return ans[h(i,j)];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n+n*n;++i){
        p[i]=i;
        ans[i]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(!vis[i][j])
                dfs(i,j,i,j,c[i][j]);
        }
    }
    while(m--){
        cin>>x>>y;
        cout<<ans[fi(h(x,y))]<<endl;
    }
    return 0;
}

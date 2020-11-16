#include <bits/stdc++.h>
using namespace std;
const int maxn=6005;

int n;
int r[maxn];
int l,k;
int dp[maxn][2];
bool vis[maxn];

struct edge
{
    int next;
    edge(int n){next=n;}
};
vector<edge> p[maxn];

void dfs(int x)
{
    vis[x]=true;
    dp[x][0]=0;
    dp[x][1]=r[x];
    for(int i=0;i<p[x].size();++i){
        int son=p[x][i].next;
        if(!vis[son])
            dfs(son);
        dp[x][0]+=max(dp[son][1],dp[son][0]);
        dp[x][1]+=dp[son][0];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>r[i];
    for(int i=1;i<=n-1;++i){
        cin>>l>>k;
        p[k].push_back(edge(l));
        vis[l]=true;
    }
    int root;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            root=i;
            break;
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);
    return 0;
}

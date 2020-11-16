#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const ll inf=1e19;

int n,x,y;
ll v;
int sz[maxn];
ll ans[maxn];
ll dp[maxn];
struct edge
{
    int next;
    ll v;
    edge(){}
    edge(int a,ll b):next(a),v(b){}
};
vector<edge> p[maxn];

void dfs1(int x)
{
    sz[x]++;
    for(int i=0;i<p[x].size();++i){
        int y=p[x][i].next;
        dp[y]=dp[x]+p[x][i].v;
        dfs1(y);
        sz[x]+=sz[y];
    }
}

void dfs2(int x)
{
    for(int i=0;i<p[x].size();++i){
        int y=p[x][i].next;
        ans[y]=ans[x]+(n-2*sz[y])*p[x][i].v;
        dfs2(y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(sz,0,sizeof(sz));
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>x>>y>>v;
        p[min(x,y)].push_back(edge(max(x,y),v));
    }
    dfs1(1);
    for(int i=2;i<=n;++i)
        ans[1]+=dp[i];
    dfs2(1);
    ll sml=inf;
    int idx;
    for(int i=1;i<=n;++i){
        if(ans[i]<sml){
            sml=ans[i];
            idx=i;
        }
    }
    /*
    for(int i=1;i<=n;++i)
        cout<<sz[i]<<" ";
    */
    cout<<idx<<endl;
    cout<<sml*2;
    return 0;
}

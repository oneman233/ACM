#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;
typedef long long ll;

ll sum=0;
map<pair<int,int>,ll> mp;
int n,m;
int p[maxn];
struct edge
{
    int x,y,v;
    bool operator < (edge &e)
    {
        return v<e.v;
    }
}ee[maxn],e[maxn];
int head[maxn],tot=0;
bool vis[maxn];

void add(int x,int y,int v)
{
    e[++tot].v=v;
    e[tot].y=y;
    e[tot].x=head[x];
    head[x]=tot;
}

int _find(int x)
{
    if(x!=p[x])
        p[x]=_find(p[x]);
    return p[x];
}

void kk()
{
    sort(ee,ee+m);
    for(int i=1;i<=n;++i)
        p[i]=i;
    for(int i=0;i<m;++i){
        int x=ee[i].x;
        int y=ee[i].y;
        int rx=_find(x);
        int ry=_find(y);
        if(rx!=ry){
            p[rx]=ry;
            add(x,y,ee[i].v);
            add(y,x,ee[i].v);
            sum+=ee[i].v;
        }
    }
}

int dep[maxn],fa[maxn][20],mx[maxn][20];

void dfs(int x,int f)
{
    vis[x]=1;
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(int i=1;(1<<i)<=dep[x];++i){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
    }
    for(int i=head[x];i;i=e[i].x){
        if(e[i].y!=f){
            mx[e[i].y][0]=e[i].v;
            dfs(e[i].y,x);
        }
    }
}

int lg(int x)
{
    return (int)log2(x)+1;
}

void lca(int x,int y)
{
	int tmp=mp[{x,y}];
    if(_find(x)!=_find(y)){
        printf("-1\n");
        return;
    }
    if(dep[x]<dep[y]){
        int tmp=x;
        x=y;
        y=tmp;
    }
    int dif=dep[x]-dep[y],ans=0;
    for(int i=0;i<lg(dif);++i){
        if(dif&(1<<i)){
            ans=max(ans,mx[x][i]);
            x=fa[x][i];
        }
    }
    if(x==y)
    	ans=sum-ans+tmp,
        printf("%lld\n",ans);
    else{
        for(int i=lg(dep[x])-1;i>=0;--i){
            if(fa[x][i]!=fa[y][i]){
                ans=max(ans,mx[x][i]);
                ans=max(ans,mx[y][i]);
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        ans=max(ans,mx[x][0]);
        ans=max(ans,mx[y][0]);
        ans=sum-ans+tmp,
		printf("%lld\n",ans);
    }
}

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<m;++i)
        scanf("%lld %lld %lld",&ee[i].x,&ee[i].y,&ee[i].v),
        mp[{ee[i].x,ee[i].y}]=ee[i].v,
        mp[{ee[i].y,ee[i].x}]=ee[i].v;
    kk();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            mx[i][0]=0;
            dfs(i,i);
        }
    }
    int q,qx,qy;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&qx,&qy);
        lca(qx,qy);
    }
    return 0;
}

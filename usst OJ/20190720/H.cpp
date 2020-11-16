#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const double inf=1000000001.0;

int fa[1005][20],dp[1005];
int n,m,k,x,y;
int fc[100005];
struct point
{
    double x,y;
}p[10005];
struct circle
{
    double r;
    point p;
    bool operator <(circle &c)
    {
        return r<c.r;
    }
}c[1005];
vector<int> pic[1005];

double len(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool pc(point p,circle c)
{
    if(len(p,c.p)<=c.r)
        return true;
    return false;
}

bool cc(circle a,circle b)
{
    if(len(a.p,b.p)+min(a.r,b.r)<=max(a.r,b.r))
        return true;
    return false;
}

int lg(int x)
{
    return (int)log2(x)+1;
}

void dfs(int x,int f)
{
    dp[x]=dp[f]+1;
    fa[x][0]=f;
    for(int i=1;(1<<i)<=dp[x];++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<pic[x].size();++i)
        if(pic[x][i]!=f)
            dfs(pic[x][i],x);
}

int lca(int x,int y)
{
    if(dp[x]<dp[y]){
        int tmp=x;
        x=y;
        y=tmp;
    }
    if(dp[x]!=dp[y]){
        int dif=dp[x]-dp[y];
        for(int i=0;i<lg(dif);++i)
            if(dif&(1<<i))
                x=fa[x][i];
    }
    if(x==y)
        return x;
    else{
        for(int i=lg(dp[x]);i>=0;--i){
            if(fa[x][i]!=fa[y][i]){
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        return fa[x][0];
    }
}

void build()
{
    for(int i=0;i<m;++i){
        for(int j=i+1;j<=m;++j){
            if(cc(c[i],c[j])){
                pic[i].pb(j);
                pic[j].pb(i);
                break;
            }
        }
    }
}

int findc(int x)
{
    for(int i=0;i<=m;++i)
        if(pc(p[x],c[i]))
            return i;
}

void pre()
{
    memset(dp,0,sizeof(dp));
    memset(fa,0,sizeof(fa));
    memset(p,0,sizeof(p));
    memset(c,0,sizeof(c));
    c[0].r=inf;
}

int main()
{
    pre();
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lf %lf",&p[i].x,&p[i].y);
    for(int i=1;i<=m;++i)
        scanf("%lf %lf %lf",&c[i].r,&c[i].p.x,&c[i].p.y);
    sort(c,c+1+m);
    build();
    dfs(m,m);
    for(int i=1;i<=n;++i){
        fc[i]=findc(i);
    }
    for(int i=1;i<=k;++i){
        scanf("%d %d",&x,&y);
        x=fc[x];
        y=fc[y];
        int f=lca(x,y);
        printf("%d\n",dp[x]+dp[y]-2*dp[f]);
    }
    return 0;
}

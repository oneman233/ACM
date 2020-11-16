#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const int maxn=500005;

int n,m,s,x,y;
int dep[maxn],fa[maxn][35];
struct edge
{
    int next;
    int to;
}e[maxn*2];
int head[maxn*2],tot=0;

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(int j=1;(1<<j)<=dep[x];j++)
        fa[x][j]=fa[fa[x][j-1]][j-1];
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
            dfs(e[i].to,x);
}

void add(int x,int y)
{
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}

int lg(int x)
{
    return (int)log2(x)+1;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]){
        int tmp=x;
        x=y;
        y=tmp;
    }
    if(dep[x]!=dep[y]){
        int dif=dep[x]-dep[y];
        for(int i=0;i<lg(dif);++i)
            if(dif&(1<<i))
                x=fa[x][i];
    }
    if(x==y)
        return x;
    else{
        for(int i=lg(dep[x])-1;i>=0;--i){
            if(fa[x][i]!=fa[y][i]){
                x=fa[x][i];
                y=fa[y][i];
            }
        }
        return fa[x][0];
    }
}

void pre()
{
    memset(head,0,sizeof(head));
    memset(dep,0,sizeof(dep));
    memset(fa,0,sizeof(fa));
}

int main()
{
    pre();
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=n-1;++i){
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(s,s);
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}
/*
5 10000 5
5 2
1 4
2 1
3 4
*/

#include <bits/stdc++.h>
using namespace std;

int t;
int dep[1005];
int fa[1005][30];
int n,m,tmp,q,u,v;
struct edge
{
    int next,to;
}e[2005];
int head[1005],tot=0;

void add(int x,int y)
{
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(int i=1;(1<<i)<=dep[x];++i)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
            dfs(e[i].to,x);
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

int main()
{
    cin>>t;
    int c=1;
    while(t--){
        memset(head,0,sizeof(head));
        memset(e,0,sizeof(e));
        tot=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>m;
            while(m--){
                cin>>tmp;
                add(i,tmp);
                add(tmp,i);
            }
        }
        dfs(1,1);
        cout<<"Case "<<c<<":"<<endl;
        cin>>q;
        while(q--){
            cin>>u>>v;
            cout<<lca(u,v)<<endl;
        }
        c++;
    }
    return 0;
}

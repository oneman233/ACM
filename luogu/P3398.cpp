#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const int maxn=100000;

int n,q,a,b,c,d;
int dep[maxn+5],fa[maxn+5][30];
int lg[maxn+5];
struct edge
{
    int to,next;
}e[maxn*2+5];
int head[maxn+5],tot=0;

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
    for(int i=head[x];i;i=e[i].next){
        if(e[i].to!=f)
            dfs(e[i].to,x);
    }
}

int lca(int x,int y)
{
    if(dep[y]>dep[x]){
        int tmp=x;
        x=y;
        y=tmp;
    }
    if(dep[x]!=dep[y]){
        int dif=dep[x]-dep[y];
        for(int i=0;i<lg[dif];++i)
            if(dif&(1<<i))
                x=fa[x][i];
    }
    if(x==y)
        return x;
    else{
        for(int i=lg[dep[x]]-1;i>=0;--i){
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
    int flg=0;
    for(int i=0;i<=maxn;++i){
        if((1<<flg)<=i)
            flg++;
        lg[i]=flg;
    }
}

bool online(int x,int a,int b)
{
    int ab=lca(a,b);
    if(dep[x]>=dep[ab]&&(lca(x,a)==x||lca(x,b)==x))
        return true;
    return false;
}

int main()
{
    pre();
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n-1;++i){
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,1);
    while(q--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int ab=lca(a,b);
        int cd=lca(c,d);
        if(online(ab,c,d)||online(cd,a,b))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

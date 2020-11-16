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
    for(int j=1;(1<<j)<=dep[x];j++)
        fa[x][j]=fa[fa[x][j-1]][j-1];
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
            dfs(e[i].to,x);
}

int lg(int x){return (int)log2(x)+1;}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    if(dep[x]!=dep[y]){
        int dif=dep[x]-dep[y];
        for(int i=0;i<lg(dif);++i)
            if(dif&(1<<i))
                x=fa[x][i];
    }
    if(x==y)
        return x;
    for(int i=lg(dep[x])-1;i>=0;--i){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

int dis(int x,int y)
{
	int l=lca(x,y);
	return dep[x]-dep[l]+dep[y]-dep[l];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    s=1;
    dfs(s,s);
    int ans=0;
	for(int i=1;i<=n;++i)
    {
		for(int j=1;j<=n;++j)
		{
			ans+=dis(i,j)*dis(i,j);
		}
	}
	cout<<ans;
    return 0;
}

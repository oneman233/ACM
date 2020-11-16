#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int n,q,dep[MAXN],lg[MAXN],fa[MAXN][35];
vector<int> e[MAXN];
int c[MAXN];
int tot=0;
map<int,int> mp;
int p[MAXN][2];
vector<int> sav[MAXN];

void dfs(int now,int pa)
{
	sav[mp[c[now]]].push_back(now);
    dep[now]=dep[pa]+1;
    fa[now][0]=pa;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(auto to:e[now])
        if(to!=pa) dfs(to,now);
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return x;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int dis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int main()
{
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i) {
		scanf("%d",c+i);
		if(!mp[c[i]]) mp[c[i]]=++tot;
	}
    for(int i=0,x,y;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y),e[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=tot;++i) {
		p[i][0]=p[i][1]=sav[i][0];
		for(int j=1;j<sav[i].size();++j) {
			int a=dis(p[i][0],sav[i][j]);
			int b=dis(p[i][1],sav[i][j]);
			if(a<b) {
				swap(a,b);
				swap(p[i][0],p[i][1]);
			}
			if(a>dis(p[i][0],p[i][1]))
				swap(p[i][1],sav[i][j]);
		}
	}
    while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(!mp[x]||!mp[y]) {
			puts("0");
			continue;
		}
		x=mp[x];y=mp[y];
		int ans=0;
		for(int i=0;i<=1;++i)
			for(int j=0;j<=1;++j)
				ans=max(ans,dis(p[x][i],p[y][j]));
		printf("%d\n",ans);
	}
    return 0;
}

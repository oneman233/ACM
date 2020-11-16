#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,c[200005];
vector<int> e[200005];
map<int,int> mp;

int dep[200005],mx=-1,p=-1,fa[200005];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	if(dep[x]>mx&&mp[x])
	{
		mx=dep[x];
		p=x;
	}
	for(auto y:e[x])
		if(y!=f)
			dfs(y,x);
}

int dis[200005];
void dfs2(int x,int f)
{
	dis[x]=dis[f]+1;
	for(auto y:e[x])
		if(y!=f)
			dfs2(y,x);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=m;++i) scanf("%d",&c[i]),mp[c[i]]=1;
	dfs(c[1],c[1]);
	int ans=p;
	while(dep[ans]!=(mx+1)/2) ans=fa[ans];
	dfs2(ans,ans);
	int check=dis[c[1]];
	for(int i=2;i<=m;++i)
		if(dis[c[i]]!=check)
			return puts("NO"),0;
	printf("YES\n%d",ans);
	return 0;
}

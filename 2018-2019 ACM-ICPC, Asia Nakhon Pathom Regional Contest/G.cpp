#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int> e[205],scc[205];
int dfn[205],low[205],timer=0,color=0,co[205];
stack<int> s;
bool vis[205];

void tarjan(int u)
{
	dfn[u]=low[u]=++timer;
	s.push(u);
	vis[u]=1;
	for(auto v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++color;
		int t;
		do
		{
			t=s.top();
			s.pop();
			co[t]=color;
			vis[t]=0;
			scc[color].push_back(t);
		}
		while(u!=t);
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i) e[i].clear(),scc[i].clear();
		timer=color=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(co,0,sizeof(co));
		while(!s.empty()) s.pop();
		for(int i=1,a,b;i<=m;++i){
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
		}
		for(int i=0;i<n;++i)
			if(!dfn[i])
				tarjan(i);
		printf("%d\n",color);
	}
	return 0;
}
/*
3
6
2 0 5 5 0
5
7 0 1 0 2 1 0 1 3 2 4 3 1 4 2
3
4 0 1 0 2 1 0 1 2
*/

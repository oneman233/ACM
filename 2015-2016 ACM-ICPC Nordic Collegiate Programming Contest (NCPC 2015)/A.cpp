#include <bits/stdc++.h>
using namespace std;

int n,m,dis,p,vis[100005];
vector<int> e[100005],d;

void dfs(int now,int fa,int dep)
{
	if(dep>dis) dis=dep,p=now;
	vis[now]=1;
	for(auto to:e[now])
		if(to!=fa) dfs(to,now,dep+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			dis=0;
			dfs(i,i,1);
			dfs(p,p,1);
			d.push_back(dis);
		}
	sort(d.begin(),d.end(),greater<int>());
	int ans=d[0];
	for(int i=1;i<d.size();i++)
		ans=max(ans/2+d[i]/2+2,max(ans,d[i]));
	printf("%d",ans-1);
	return 0;
}

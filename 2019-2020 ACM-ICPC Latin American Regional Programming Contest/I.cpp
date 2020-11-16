#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,m,vis[2005];
ll siz[2005];
vector<int> v[2005];
set<int> s;

void dfs(int now)
{
	vis[now]=1;
	for(auto to:v[now])
	{
		if(to>m) siz[now]++,s.insert(to);
		else
		{
		 	if(!vis[to]) dfs(to);
		 	siz[now]+=siz[to];
		}
		siz[now]%=mod;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		for(int j=0,y;j<x;j++)
			scanf("%d",&y),v[i].push_back(y);
	}
	dfs(1);
	printf("%lld %d",siz[1]%mod,(int)s.size());
	return 0;
}

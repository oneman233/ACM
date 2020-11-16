#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,m,k;
int a[N];
vector<pair<int,int>> e[N];
vector<int> e2[N];
struct node
{
	int u,v,w;
}o[N*10+5];
bool vis[N];
int dis[N];
int cnt[N];

void dij()
{
	for(int i=1;i<=n;++i) dis[i]=1e9;
	dis[1]=0;
	cnt[1]=1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({dis[1],1});
	while(!q.empty())
	{
		int t=q.top().second;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(auto i:e[t])
		{	
			if(dis[i.first]>dis[t]+i.second)
			{
				dis[i.first]=dis[t]+i.second;
				cnt[i.first]=cnt[t];
				q.push({dis[i.first],i.first});
			}
			else if(dis[i.first]==dis[t]+i.second)
				cnt[i.first]++;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=k;++i) scanf("%d",&x);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&o[i].u,&o[i].v,&o[i].w);
		e[o[i].u].push_back({o[i].v,o[i].w});
		e[o[i].v].push_back({o[i].u,o[i].w});	
	}
	dij();
//	for(int i=1;i<=n;++i) cout<<cnt[i]<<' ';cout<<endl;
	if(cnt[n]==1) puts("no");
	else puts("yes");
	return 0; 
} 

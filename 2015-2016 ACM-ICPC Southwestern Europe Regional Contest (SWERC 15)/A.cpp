#include <bits/stdc++.h>
using namespace std;

int a,b,n,m,dis[5005],deg[5005],pre[5005],hum[5005],g[5005],r[5005],vis[5005];
vector<int> e[5005];
queue<int> q;

void dfs(int now,int st)
{
	vis[now]=1;
	g[now]++;
	r[st]++;
	for(auto to:e[now])
		if(!vis[to]) dfs(to,st);
}

int main()
{
	scanf("%d%d%d%d",&a,&b,&n,&m);
	for(int i=0,x,y;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x++,y++;
		e[x].push_back(y);deg[y]++;
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) vis[j]=0;
		dfs(i,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(a>n-r[i]) ans++;
	printf("%d\n",ans);
	ans=0;
	for(int i=1;i<=n;i++) if(b>n-r[i]) ans++;
	printf("%d\n",ans);
	ans=0;
	for(int i=1;i<=n;i++) if(g[i]-1>=b) ans++;
	printf("%d",ans);
	return 0;
}
/*
1 1 7 8
0 4
1 2
1 5
5 2
6 4
0 1
2 3
4 5

1 2 7 6
0 1
1 2
2 3
3 4
4 5
5 6

*/

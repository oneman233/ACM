#include <bits/stdc++.h>
using namespace std;
const int N=505;

int n,m,k;
vector<int> e[N*2];
bool vis[N];
int match[N],rematch[N];

bool dfs(int u)
{
	for(auto v:e[u])
	{
		if(!vis[v])
		{
			vis[v]=1;
			if(match[v]==0||dfs(match[v]))
			{
				match[v]=u;
				rematch[u]=v;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,a,b;i<=n;++i)
	{
		scanf("%d",&a);
		for(int j=1;j<=a;++j)
		{
			scanf("%d",&b);
			e[i].push_back(b);
			e[i+n].push_back(b);
		}
	}
	int ans=0;
	for(int i=1;i<=2*n;++i)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	int cnt=0;
//	for(int i=1;i<=m;++i) printf("%d ",match[i]);puts("");
	for(int i=1;i<=m;++i)
		if(match[i]>n) cnt++;
	if(cnt>k) ans-=cnt-k;
	printf("%d",ans);
	return 0;
}

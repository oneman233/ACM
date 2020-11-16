#include <bits/stdc++.h>
using namespace std;
const int mod=9987;
const int N=1005;

int n,m;
vector<int> e[N],v[N];
double dis[N];
int pre[N][2];
bool vis[N];
typedef pair<double,int> pdi;
priority_queue<pdi,vector<pdi>,greater<pdi>> q;

void dij()
{
	for(int i=1;i<=n;++i)
		dis[i]=99999999.0;
	memset(vis,0,sizeof(vis));
	dis[1]=0.0;
//	vis[1]=1;
	q.emplace(0.0,1);
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<e[x].size();++i)
		{
			int y=e[x][i];
			int val=v[x][i];
			if(dis[x]+log(val)<dis[y])
			{
				dis[y]=dis[x]+log(val);
				q.emplace(dis[y],y);
				pre[y][0]=x;
				pre[y][1]=val;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(y);
		v[x].push_back(z);
	}
	dij();
//	for(int i=1;i<=n;++i)
//		printf("%lf ",dis[i]);puts("");
	int ans=1;
	int p=n;
	while(p!=1)
	{
		ans=(ans*pre[p][1])%mod;
		p=pre[p][0];
	}
	printf("%d",ans);
	return 0;
}

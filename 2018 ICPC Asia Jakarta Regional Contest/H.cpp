#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;

int n,m;
int sum[maxn],p[maxn],pre[maxn],id[maxn],vis[maxn],cnt[maxn];
int l,r,c,a[maxn];
ll dis[maxn];
vector<int> e[maxn];
vector<ll> val[maxn];

bool spfa()
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	vis[0]=1,dis[0]=0,cnt[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vis[now]=0;
		for(int i=0;i<e[now].size();i++)
		{
			int to=e[now][i];
			ll cost=val[now][i];
			if(dis[to]>dis[now]+cost)
			{
				dis[to]=dis[now]+cost;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
					cnt[to]++;
					if(cnt[to]>n) return false;
				}
			}
		}
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	int cnt=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[i]=p[i-1]+abs(a[i]);
		pre[i]=pre[i-1]+a[i];
		if(a[i]==0)
		{
			id[++cnt]=i;
			e[cnt].push_back(cnt-1);
			val[cnt].push_back(1);
			e[cnt-1].push_back(cnt);
			val[cnt-1].push_back(1);
		}
	}
	for(int i=0;i<m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		e[r-p[r]+1].push_back(l-p[l-1]);
		val[r-p[r]+1].push_back(pre[r]-pre[l-1]-k);
		//printf("%d->%d %d\n",r-p[r]+1,l-p[l-1],pre[r]-pre[l-1]-k);
	}
	for(int i=1;i<=cnt;i++) e[0].push_back(i),val[0].push_back(0);
	if(!spfa())
	{
		printf("Impossible");
		return 0;
	}
	for(int i=cnt+1;i>=1;i--)
		dis[i]=dis[i]-dis[i-1],a[id[i]]=dis[i];	
	for(int i=1;i<=n;i++) 
		if(a[i]==0) printf("%d ",-1);
		else printf("%d ",a[i]);
	return 0;
}

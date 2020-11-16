#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
const int inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> pii;

int n,m,k,E,d;
vector<int> e[N],v[N];
int p[N],a[N],b[N];

void add(int x,int y,int val)
{
	e[x].push_back(y);
	v[x].push_back(val);
}

int dp[N];
bool can[N],vis[N];
int dis[N];

int dij()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.emplace(0,1);
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();++i)
		{
			int y=e[x][i];
			int val=v[x][i];
			if(can[y]&&dis[x]+val<dis[y])
			{
				dis[y]=dis[x]+val;
				q.emplace(dis[y],y);
			}
		}
	}
	return dis[m];
}

int L(int l,int r)
{
	for(int i=1;i<=m;++i)
		can[i]=1;
	for(int i=1;i<=d;++i)
	{
		if(b[i]<l||a[i]>r) continue;
		can[p[i]]=0;
	}
	int ret=dij();
//	printf("? %lld %lld %lld\n",l,r,(ret==inf?9999:ret));
	return ret;
}

void gao()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0]=-k;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j+1<=i;++j)
		{
			if(L(j+1,i)==inf) continue;
			dp[i]=min(dp[i],dp[j]+(i-j)*L(j+1,i)+k);
		}
	}
//	for(int i=1;i<=n;++i) printf("%lld ",dp[i]);
	printf("%lld",dp[n]);
}

signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&E);
	for(int i=1,x,y,z;i<=E;++i)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	scanf("%lld",&d);
	for(int i=1;i<=d;++i)
		scanf("%lld%lld%lld",&p[i],&a[i],&b[i]);
	gao();
	return 0;
}
/*
5 5 10 8
1 2 1
1 3 3
1 4 2
2 3 2
2 4 4
3 4 1
3 5 2
4 5 2
4
2 2 3
3 1 1
3 3 3
4 4 5
*/

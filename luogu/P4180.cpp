#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=1e6+5;
int inf=1e18;

struct edge
{
	int to,val;
};
vector<edge> e[N];

struct node
{
	int x,y,v;
}eg[M];

void add(int a,int b,int c)
{
	e[a].push_back({b,c});
	e[b].push_back({a,c});
}

int fa[N][35],dep[N],mx[N][35],mn[N][35];
void dfs(int x,int f)
{
	fa[x][0]=f;
	for(auto i:e[x])
	{
		if(i.to==f) continue;
		dep[i.to]=dep[x]+1;
		mx[i.to][0]=i.val;
		mn[i.to][0]=-inf;
		dfs(i.to,x);
	}
}

int n,m;
void cal()
{
	for(int i=1;i<=30;++i)
	{
		for(int j=1;j<=n;++j)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
			mx[j][i]=max(mx[j][i-1],mx[fa[j][i-1]][i-1]);
			mn[j][i]=max(mn[j][i-1],mn[fa[j][i-1]][i-1]);
			if(mx[j][i-1]>mx[fa[j][i-1]][i-1])
				mn[j][i]=max(mn[j][i],mx[fa[j][i-1]][i-1]);
			else if(mx[j][i-1]<mx[fa[j][i-1]][i-1])
				mn[j][i]=max(mn[j][i],mx[j][i-1]);
		}
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=30;i>=0;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y) return x;
	for(int i=30;i>=0;--i)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],
			y=fa[y][i];
	return fa[x][0];
}

int qmax(int u,int v,int val)
{
	int ans=-inf;
	for(int i=30;i>=0;--i)
	{
		if(dep[fa[u][i]]>=dep[v])
		{
			if(val!=mx[u][i])
				ans=max(ans,mx[u][i]);
			else
				ans=max(ans,mn[u][i]);
			u=fa[u][i];
		}
	}
	return ans;
}

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int F[N];
int _find(int x)
{
	if(x!=F[x]) F[x]=_find(F[x]);
	return F[x];
}

bool flg[M];
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&eg[i].x,&eg[i].y,&eg[i].v);
	}
	sort(eg+1,eg+1+m,cmp);
	for(int i=1;i<=n;++i)
	{
		F[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		int fx=_find(eg[i].x);
		int fy=_find(eg[i].y);
		if(fx!=fy)
		{
			cnt+=eg[i].v;
			F[fx]=fy;
			add(eg[i].x,eg[i].y,eg[i].v);
			flg[i]=1;
		}
	}
	mn[1][0]=-inf;
	dep[1]=1;
	dfs(1,-1);
	cal();
	int ans=inf;
	for(int i=1;i<=m;++i)
	{
		if(flg[i]) continue;
		int x=eg[i].x;
		int y=eg[i].y;
		int v=eg[i].v;
		int l=lca(x,y);
		int mxu=qmax(x,l,v);
		int mxv=qmax(y,l,v);
		ans=min(ans,cnt-max(mxu,mxv)+v);
	}
	printf("%lld",ans);
	return 0;
}

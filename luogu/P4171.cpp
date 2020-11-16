#include <bits/stdc++.h>
using namespace std;
const int N=205;

int t,n,m;
vector<int> e[N];
char a[10],b[10];

void add(int x,int y)
{
	e[x].push_back(y);
}

int dfn[N],low[N],timer=0,c[N],color=0;
vector<int> scc[N];
stack<int> s;
bool vis[N];

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
		int t;
		color++;
		do
		{
			t=s.top();
			s.pop();
			vis[t]=0;
			c[t]=color;
		}
		while(t!=u);
	}
}

int cal(char *s)
{
	int l=strlen(s);
	int ret=0,base=1;
	for(int i=l-1;i>=1;--i)
	{
		ret+=(s[i]-'0')*base;
		base*=10;
	}
	return ret;
}

void gao()
{
	timer=0,color=0;
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=2*n;++i)
		if(!dfn[i])
			tarjan(i);
	bool can=1;
	for(int i=1;i<=n;++i)
		if(c[i]==c[i+n])
		{
			can=0;
			break;
		}
	if(can) puts("GOOD");
	else puts("BAD");
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=2*n;++i)
			e[i].clear();
		for(int i=1;i<=m;++i)
		{
			scanf("%s%s",a,b);
//			printf("%s %s\n",a,b);
			int vi=cal(a),vj=cal(b);
//			printf("%d %d\n",vi,vj);
			if(a[0]=='m'&&b[0]=='m')
				add(vi+n,vj),add(vj+n,vi);
			else if(a[0]=='m'&&b[0]=='h')
				add(vi+n,vj+n),add(vj,vi);
			else if(a[0]=='h'&&b[0]=='m')
				add(vi,vj),add(vj+n,vi+n);
			else if(a[0]=='h'&&b[0]=='h')
				add(vi,vj+n),add(vj,vi+n);
		}
		gao();
	}
	return 0;
}

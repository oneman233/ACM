#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=505*505;
const int mv[2][2]={0,1,1,0};
int n,m,dep[MAXN],lg[MAXN],fa[MAXN][32],a[505][505],val[MAXN],q,ua[MAXN];
int mx[MAXN][32];
struct edge
{
	int v,x,y;
	edge(){}
	edge(int x,int y,int v):x(x),y(y),v(v){}
};
vector<edge> ee;
vector<int> e[MAXN];

inline bool cmp(edge a,edge b){return a.v<b.v;}

int _find(int x)
{
	if(x==ua[x]) return x;
	return ua[x]=_find(ua[x]);
}

inline void _merge(int x,int y)
{
	x=_find(x),y=_find(y);
	if(x!=y) ua[x]=y;
}

void dfs(int now,int pa)
{
	dep[now]=dep[pa]+1;
	fa[now][0]=pa;
	mx[now][0]=max(val[now],val[pa]);
	for(int i=1;(1<<i)<=dep[now];i++)
		fa[now][i]=fa[fa[now][i-1]][i-1],
		mx[now][i]=max(mx[now][i-1],mx[fa[now][i-1]][i-1]);
	for(auto to:e[now])
		if(to!=pa) dfs(to,now);
}

int lca(int x,int y)
{
	int ret=val[x];
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) 
		ret=max(ret,mx[x][lg[dep[x]-dep[y]]-1]),
		x=fa[x][lg[dep[x]-dep[y]]-1];
	if(x==y) return ret;
	for(int i=lg[dep[x]]-1;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			ret=max(ret,mx[x][i]);
			ret=max(ret,mx[y][i]);
			x=fa[x][i],y=fa[y][i];
		}
	ret=max(ret,mx[x][0]);
	ret=max(ret,mx[y][0]);
	return ret;
}

inline int get(int x,int y)
{
	return x*m+y;
}

int main()
{
	for(int i=1;i<MAXN;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n*m;i++) ua[i]=i;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]),val[get(i,j)]=a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<2;k++)
			{
				int dx=i+mv[k][0],dy=j+mv[k][1];
				if(dx==n||dy==m) continue;
				int v=max(a[i][j],a[dx][dy]);
				ee.emplace_back(get(i,j),get(dx,dy),v);
			}
	sort(ee.begin(),ee.end(),cmp);
	for(auto p:ee)
		if(_find(p.x)!=_find(p.y)) 
		{
			e[p.x].push_back(p.y),e[p.y].push_back(p.x);
			_merge(p.x,p.y);
		}
	dfs(0,n*m);
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1--,y1--,x2--,y2--;
		printf("%d\n",lca(get(x1,y1),get(x2,y2)));
	}
	return 0;
}

/*

*/

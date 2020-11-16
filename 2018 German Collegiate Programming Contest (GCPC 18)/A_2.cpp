#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+1e5;
const int mv[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,dep[MAXN],lg[MAXN],fa[MAXN][32],x[MAXN],y[MAXN],vis[MAXN],q;
vector<int> e[MAXN];
char s[1055][2055];

void dfs(int now,int pa)
{
	vis[now]=1;
	dep[now]=dep[pa]+1;
	fa[now][0]=pa;
	for(int i=1;(1<<i)<=dep[now];i++)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto to:e[now])
		if(to!=pa&&!vis[to]) dfs(to,now);
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]-1];
	if(x==y) return x;
	for(int i=lg[dep[x]]-1;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

inline int get(int x,int y)
{
	return (x-1)*m+y-1;
}

inline ll dis(int x,int y)
{
	int f=lca(x,y);
	return dep[x]+dep[y]-2*dep[f];
}

int main()
{
	for(int i=1;i<MAXN;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	scanf("%d%d ",&n,&m);
	for(int i=0;i<=n;i++)
		scanf("%[^\n]%*c",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2*m;j++)
		{
			if(j&1) continue;
			for(int k=0;k<4;k++)
			{
				int dx=i+mv[k][0],dy=j+mv[k][1];
				if(dx<1||dx>n||dy<=1||dy>2*m) continue;
				if(k==0||k==1)
					if(s[dx][dy]=='|') continue;
				if(k==2&&s[i][j]=='_') continue;
				if(k==3&&s[dx][dy]=='_') continue;
				int x,y,tx,ty;
				x=i,tx=dx;
				y=j/2,ty=(j+2*mv[k][1])/2;
				e[get(x,y)].push_back(get(tx,ty));
				e[get(tx,ty)].push_back(get(x,y));
			}
		}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
		scanf("%d%d",x+i,y+i);
	dfs(get(x[0],y[0]),get(x[0],y[0]));
	ll ans=0;
	for(int i=1;i<q;i++)
		ans+=dis(get(x[i],y[i]),get(x[i-1],y[i-1]));
	printf("%lld",ans);
	return 0;
}

/*
2 6
 _ _ _ _ _ _ 
|  _ _ _ _ _|
|_ _ _ _ _ _|
5
1 5
1 1
1 6
1 1
1 5

5 5
 _ _ _ _ _ 
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|
7
4 4
1 4
3 1
4 5
1 2
2 2
5 4
*/

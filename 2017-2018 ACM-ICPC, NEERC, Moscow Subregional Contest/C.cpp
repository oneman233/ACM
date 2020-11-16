#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[100005];
int sz[100005],x[100005],y[100005];

void dfs(int x,int f)
{
	sz[x]=1;
	for(auto y:e[x])
	{
		if(y==f) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}

void gao2(int u,int f,int X,int Y)
{
	x[u]=X;
	y[u]=Y;
	int son=0;
	for(auto v:e[u])
		if(sz[son]<sz[v]&&v!=f)
			son=v;
	if(son==0) return;
	int sum=0;
	for(auto v:e[u])
	{
		if(v==f||v==son) continue;
		gao2(v,u,X+1,Y+sum);
		sum+=sz[v];
	}
	gao2(son,u,X,Y+max(sum,1));
}

void gao()
{
	dfs(1,1);
	gao2(1,1,1,1);
	for(int i=1;i<=n;++i) printf("%d %d\n",y[i],x[i]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	gao();
	return 0;
}
/*
6
1 2
1 3
1 4
4 5
4 6

6
1 2
1 3
1 4
1 5
1 6

8
1 2
2 5
2 6
1 3
3 7
1 4
4 8
*/

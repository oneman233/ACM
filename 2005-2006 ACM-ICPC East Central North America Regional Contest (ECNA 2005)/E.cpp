#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,Case=1;
int x[25],y[25],w[25];
int mp[20][20];
bool flg=0;
int timer=0;
int dfn[20],low[20];
void tarjan(int u,int f)
{
	dfn[u]=low[u]=++timer;
	for(int v=1;v<=n;++v)
	{
		if(!mp[u][v]) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v]) flg=1;
		}
		else if(v!=f) low[u]=min(low[u],dfn[v]);
	}
}

int main()
{
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		for(int i=0;i<m;++i)
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
		int ans=1e9;
		for(int i=1;i<(1<<m);++i)
		{
			int sum=0;
			for(int j=0;j<m;++j)
				if(i&(1<<j)) mp[x[j]][y[j]]=mp[y[j]][x[j]]=w[j],sum+=w[j];
			flg=0;timer=0;
			tarjan(1,1);
			bool can=1;
			for(int i=1;i<=n;++i)
			{
				if(!dfn[i])
				{
					can=0;
					break;
				}
			}
			if(can&&!flg) ans=min(ans,sum);
			for(int i=1;i<=n;++i) dfn[i]=low[i]=0;
			for(int j=0;j<m;++j)
				if(i&(1<<j)) mp[x[j]][y[j]]=mp[y[j]][x[j]]=0;
		}
		if(ans==1e9) printf("There is no reliable net possible for test case %d.\n",Case);
		else printf("The minimal cost for test case %d is %d.\n",Case,ans);
		Case++;
	}
	return 0;
}
/*
4 5
1 2 1
1 3 2
2 4 2
3 4 1
2 3 1
2 1
1 2 5
0 0
*/

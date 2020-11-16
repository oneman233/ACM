#include <bits/stdc++.h>
#define int long long
using namespace std;

int _,m,n,k;
int dp[10005];
int p[205],c[205],in[205];
vector<pair<int,int>> e[205];
vector<int> sz[205];
bool vis[205];

void gao2(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	int pos=0;
	for(int i=0;i<sz[x].size();++i)
	{
		int all=sz[x][i];
		int tmp=0;
		for(int j=pos;j<pos+all;++j)
		{
			pair<int,int> pr=e[x][j];
			if(in[pr.first]!=0) gao2(pr.first);
			tmp+=c[pr.first]*pr.second;
		}
		pos+=all;
		c[x]=min(c[x],tmp);
	}
}

void gao(int Case)
{
	int ans=0;
	scanf("%lld%lld%lld",&m,&n,&k);
	for(int i=1;i<=n;++i) e[i].clear(),sz[i].clear(),in[i]=0,c[i]=0x3f3f3f3f,vis[i]=0;
	for(int i=1,flg;i<=n;++i)
	{
		scanf("%lld",&flg);
		if(flg==0) scanf("%lld",&p[i]);
		else if(flg==1) scanf("%lld%lld",&c[i],&p[i]);
	}
	for(int i=1,x,y;i<=k;++i)
	{
		scanf("%lld%lld",&x,&y);
		sz[x].push_back(y);
		in[x]++;
		for(int j=1,u,v;j<=y;++j)
		{
			scanf("%lld%lld",&u,&v);
			e[x].emplace_back(u,v);
		}
	}
	for(int i=1;i<=n;++i) gao2(i);
	for(int i=1;i<=m;++i) dp[i]=-0x3f3f3f3f;
	dp[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=c[i];j<=m;++j)
			dp[j]=max(dp[j],dp[j-c[i]]+p[i]),
			ans=max(ans,dp[j]);
	printf("Case #%lld: %lld\n",Case,ans);
}

signed main()
{
	scanf("%lld",&_);
	for(int Case=1;Case<=_;++Case) gao(Case);
	return 0;
}

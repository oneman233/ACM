#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
typedef pair<int,int> pii;

int n,m;
vector<int> e[N],v[N];
int d[N],dp[N];

void topo()
{
	queue<int> q;
	for(int i=1;i<=n;++i)
		if(d[i]==0) q.push(i);
	while(!q.empty())
	{
		int f=q.front();q.pop();
		for(int i=0;i<e[f].size();++i)
		{
			dp[e[f][i]]=max(dp[e[f][i]],dp[f]+v[f][i]);
			d[e[f][i]]--;
			if(d[e[f][i]]==0) q.push(e[f][i]);
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
		d[y]++;
	}
	topo();
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}

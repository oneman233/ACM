#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll dp[100005][2][2];
int deg[100005],n,a[100005],b[100005],st[100005];

void dfs(int now)
{
	if(a[now]!=0) dfs(a[now]);
	if(b[now]!=0) dfs(b[now]);
	for(int i1=0;i1<2;i1++)
		for(int j1=0;j1<2;j1++)
			for(int i2=0;i2<2;i2++)
				for(int j2=0;j2<2;j2++)
				{
					ll &x=dp[now][!(i1&i2)][((i1^j1)&(i2^j2))!=(i1&i2)];
					x+=dp[a[now]][i1][j1]*dp[b[now]][i2][j2]%mod;
					x%=mod;
				}
	if(st[now]==1) 
		dp[now][1][0]+=dp[now][0][1],dp[now][1][1]+=dp[now][0][0],dp[now][0][0]=dp[now][0][1]=0;
	else if(st[now]==0)
		dp[now][0][0]+=dp[now][1][1],dp[now][0][1]+=dp[now][1][0],dp[now][1][1]=dp[now][1][0]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			dp[now][i][j]%=mod;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",a+i,b+i,st+i);
		deg[a[i]]++,deg[b[i]]++;
	}
	dp[0][0][0]=dp[0][1][0]=1;
	queue<int> q;
	for(int i=1;i<=n;i++) 
		if(!deg[i]) 
		{
			dfs(i);
			printf("%lld",(dp[i][0][1]+dp[i][1][1])%mod);
			break;
		}
	return 0;
}

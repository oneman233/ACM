#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
ll dp[105][2];

void solve()
{
	scanf("%d%d",&n,&k);
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]+=dp[i-1][1];
		if(i>=k) dp[i][0]+=dp[i-k][1];
		dp[i][1]+=dp[i-1][0];
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=dp[i][0];
	printf("%lld",ans);
}

int main()
{
	solve();	
	return 0;
}

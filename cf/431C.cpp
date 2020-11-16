#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=305;

int n,k,d;
ll dp[maxn][2];

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	dp[0][0]=1;
	for(int i=0;i<=n;++i)
	{
		for(int j=1;j<=k;++j)
			dp[i+j][1]=(dp[i+j][1]+dp[i][1])%mod;
		for(int j=1;j<=k;++j)
		{
			if(j>=d) dp[i+j][1]=(dp[i+j][1]+dp[i][0])%mod;
			else dp[i+j][0]=(dp[i+j][0]+dp[i][0])%mod;
		}
	}
//	for(int i=1;i<=n;++i) cout<<dp[i][0]<<' ';cout<<endl;
//	for(int i=1;i<=n;++i) cout<<dp[i][1]<<' ';cout<<endl;
	printf("%lld",dp[n][1]);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long ll;

int n,a;
int cnt[maxn];
ll dp[maxn],ans=0ll;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=100000;++i)
	{
		dp[i]=max(dp[i-1],dp[i-2]+(ll)i*cnt[i]);
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}

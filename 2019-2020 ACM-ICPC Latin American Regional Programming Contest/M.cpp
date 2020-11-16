#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x;
int a[1005];
int dp[1005];

int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),dp[i]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(a[i]-a[j]<=x) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}

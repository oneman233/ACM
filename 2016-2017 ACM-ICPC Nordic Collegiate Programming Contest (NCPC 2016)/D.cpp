#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int n;
ll ans=100,a[400],dp[400];

int main()
{
	scanf("%d",&n);
	dp[0]=100;
	for(int i=0;i<n;i++)
	{
		scanf("%llu",&a[i]);
		for(int j=0;j<i;j++)
			dp[i]=max(dp[i],dp[j]/a[j]*a[i]+dp[j]%a[j]);
		dp[i]=max(dp[i],dp[i-1]);
		ans=max(dp[i],ans);
		//printf("! %llu\n",dp[i]); 
	}
	printf("%llu",ans);
	return 0;
}

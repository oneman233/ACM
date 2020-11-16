#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,num[505],sum,dp[5005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	cin>>sum;
	for(int i=1;i<=sum;i++)
		dp[i]=100000;
	dp[0]=0;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(num[j]<=i)
				dp[i]=min(dp[i-num[j]]+1,dp[i]);
		}
	}
	///对钱数去遍历可能的硬币
	cout<<dp[sum];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2005;
typedef long long ll;
const ll mod=2147483647;

int n,a[N];
ll dp[N][N];

ll gao(int l,int r,int i)
{
	if(dp[l][r]!=0)
		return dp[l][r];
	if(i==n+1)
	{
		dp[l][r]=1;
		return 1; 
	}
	if(a[i]<=l||a[i]>=r)
	{
		if(a[i]<=l) dp[l][r]=(dp[l][r]+gao(a[i],r,i+1))%mod;
		else dp[l][r]=(dp[l][r]+gao(l,a[i],i+1))%mod;
	}
	else
	{
		dp[l][r]=(dp[l][r]+gao(a[i],r,i+1))%mod;
		dp[l][r]=(dp[l][r]+gao(l,a[i],i+1))%mod;
	}
	return dp[l][r];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		scanf("%d",&a[i]);
	printf("%lld",gao(a[0],a[1],2));
	return 0;
}
/*
5
2 6 5 1 4 3
20
3 21 10 15 6 9 2 5 20 13 17 19 14 7 11 18 16 12 1 8 4
*/

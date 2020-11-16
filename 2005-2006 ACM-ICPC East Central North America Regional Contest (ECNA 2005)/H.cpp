#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

int n,Case=1;
int a[1005];
int dp[1005][1005];

int dfs(int l,int r,int turn)
{
	if(l==r) return 0;
	if(dp[l][r]!=0) return dp[l][r];
	if(turn==1)
		dp[l][r]=max(a[r]+dfs(l,r-1,1-turn),a[l]+dfs(l+1,r,1-turn));
	else if(turn==0)
	{
		if(a[l]>a[r]) dp[l][r]=dfs(l+1,r,1-turn);
		else if(a[l]<a[r]) dp[l][r]=dfs(l,r-1,1-turn);
		else dp[l][r]=max(dfs(l+1,r,1-turn),0*dfs(l,r-1,1-turn));
	}
	return dp[l][r];
}

signed main()
{
	while(~scanf("%lld",&n))
	{
		if(n==0) break;
		memset(dp,0,sizeof(dp));
		int sum=0;
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]),sum+=a[i];
		int ans=2*dfs(1,n,1)-sum;
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",Case,ans);
		Case++;
	}
	return 0;
}
/*
6 2 5 9 8 2 2
*/

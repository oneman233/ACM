#include <bits/stdc++.h>
using namespace std;

int n,m,a[5005],s[5005];
int dp[5005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+(a[i]>=m);
	memset(dp,0xc0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(s[i]-s[j]>=(i-j+2)/2) dp[i]=max(dp[i],dp[j]+1);
	printf("%d",dp[n]<0?0:dp[n]);
	return 0;
}
/*
5 2
10 3 2 3 2
*/

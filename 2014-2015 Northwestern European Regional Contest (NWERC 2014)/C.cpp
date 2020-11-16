#include <bits/stdc++.h>
using namespace std;

int n,m,dp[2005][25],a[2005],pre[2005];

int gao(int x)
{
	int t=x%10;
	if(t>=5) return x/10*10+10;
	return x/10*10;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+1;j++)
			for(int k=0;k<i;k++)
				dp[i][j]=min(dp[i][j],dp[k][j-1]+gao(pre[i]-pre[k]));
	int ans=0x3f3f3f3f;
	for(int i=1;i<=m+1;i++) ans=min(gao(dp[n][i]),ans);
	printf("%d",ans);
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
char mp[1005][1005],s[1005];
int dp[1005][1005][2],ans=1;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j) mp[i][j]=s[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='G') dp[i][j][1]=1;
			else dp[i][j][0]=1;
			int t=min(dp[i-1][j-1][0],dp[i-1][j][0]);
			t=min(t,dp[i-1][j-1][1]);
			t=min(t,dp[i-1][j][1]);
			for(int k=0;k<2;k++)
			{
				if(mp[i][j]!=mp[i][j-1])
				{
					dp[i][j][k]=1;
					continue;
				}
				dp[i][j][k]=max(dp[i][j][k],min(t,dp[i][j-1][k^g])+1),
				ans=max(ans,dp[i][j][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",dp[i][j][0]," \n"[j==m]);
	printf("%d",ans);
	return 0;
}

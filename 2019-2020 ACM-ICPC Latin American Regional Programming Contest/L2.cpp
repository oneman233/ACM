#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
char mp[1005][1005],s[1005];
int dp[1005][1005],ans=1;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j) mp[i][j]=s[j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]!=mp[i][j-1]||mp[i-1][j]!=mp[i-1][j-1])
			{
				dp[i][j]=1;
				continue;
			}
			dp[i][j]=max(dp[i][j],min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1),
			ans=max(ans,dp[i][j]);
		}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			printf("%d%c",dp[i][j]," \n"[j==m]);
	printf("%d",ans*ans);
	return 0;
}

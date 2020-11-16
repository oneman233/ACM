#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a,b;
	int dp[205][205];
	int ans=0;
	cin>>a;
	cin>>b;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=a.length();i++)
	{
		for(int j=1;j<=b.length();j++)
		{
			if(a[i]==b[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				//确保下标不会越界
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[a.length()][b.length()];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n;
ll dp[100005];
char s[100005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i]+dp[i-1])%mod;
		if(s[i]=='E'&&s[i-1]=='N'||s[i]=='W'&&s[i-1]=='N'||s[i]=='W'&&s[i-1]=='S'||s[i]=='E'&&s[i-1]=='S')
			 dp[i]=(dp[i]+dp[i-2])%mod;
	}
	printf("%lld",dp[n]);
	return 0;
}

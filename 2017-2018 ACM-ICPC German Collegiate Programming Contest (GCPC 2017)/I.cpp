#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;

int n,m,a[N];
int dp[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=m;++i) dp[i]=0;
	for(int i=m+1;i<=n;++i){
		dp[i]=max(dp[i-1],dp[i-m]+a[i]);
	}
	printf("%d",dp[n]);
	return 0;
}

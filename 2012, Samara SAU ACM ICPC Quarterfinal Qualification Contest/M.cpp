#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int dp[200005],a[200005],pre[200005],n;
vector<int> v[200005];


int main()
{
	scanf("%d",&n);
	for(int i=0;i<=200000;i++) v[i].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=v[a[i]][v[a[i]].size()-1];
		v[a[i]].push_back(i);
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[1]=0;
	for(int i=2;i<=n;i++)
		dp[i]=min(dp[i-1],dp[pre[i]])+1;
	printf("%d",dp[n]);
	return 0;
}

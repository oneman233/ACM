#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,w,dp[5005],ans;
pii a[5005];

int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),a[i]={x,i};
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int k=1;k<i;k++)
			if(a[k].first<a[i].first&&abs(a[i].second-a[k].second)<=w)
				dp[i]=max(dp[i],dp[k]+1),ans=max(dp[i],ans);
	printf("%d",ans);
	return 0;
}

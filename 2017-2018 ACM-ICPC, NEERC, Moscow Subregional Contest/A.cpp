#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;

void gao()
{
	if(k>=n)
	{
		printf("1");
		return;
	}
	int ans=1e9;
	for(int j=1;j<k;++j)
	{
		int cnt=1;
		ll now=j;
		now+=min(now,(n-now)/2);
		while(now<n)
		{
			cnt++;
			if(now+(k-j)>=n) break;
			now+=min(now,(n-now)/2);
		}
		ans=min(ans,cnt);
	}
	printf("%lld",ans);
}

int main()
{
	scanf("%lld%lld",&n,&k);
	gao();
	return 0;
}

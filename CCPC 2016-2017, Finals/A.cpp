#include <bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
	int _;
	scanf("%d",&_);
	for(int i=1;i<=_;i++)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n,greater<int>());
		for(int i=1;i<=n;i++)
			if(i%3) ans+=a[i-1];
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}

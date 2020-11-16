#include <bits/stdc++.h>
using namespace std;

int n,a[10005],cnt[10005];

void solve()
{
	int ans=0;
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i),cnt[a[i]]++;
	for(int i=0;i<=10000;i++) ans=max(ans,cnt[i]+cnt[i+1]);
	printf("%d\n",ans);
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
/*
2
3
1 2 3
5
2 2 3 4 5
*/

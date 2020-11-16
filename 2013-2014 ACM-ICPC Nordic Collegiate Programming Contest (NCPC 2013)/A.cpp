#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	ll ans=0;
	sort(a,a+n,greater<ll>());
	for(int i=0;i<n;i++) ans=max(ans,a[i]+i+1);
	printf("%lld",ans+1);
	return 0;
}

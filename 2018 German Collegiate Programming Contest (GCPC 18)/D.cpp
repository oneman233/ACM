#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1000005],b[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)s+=a[i];
		else s-=a[i];
		b[i]=s;
	}
	ll l=0,r=1e18;
	for(int i=1;i<=n;i++)
	{
		//printf("%lld ",b[i]);
		if(i&1)r=min(r,b[i]);
		else l=max(l,b[i]);
	}
	printf("%lld\n",max(0LL,r-l+1));
	return 0;
}

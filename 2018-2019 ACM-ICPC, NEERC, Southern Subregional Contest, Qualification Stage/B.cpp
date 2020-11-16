#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
ll n,h,p[200005],ans;
pair<ll,ll> a[200005];
bool ok(int l,int ed)
{
	return p[ed]-p[l]<h; 
}
int main()
{
	scanf("%lld%lld",&n,&h);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	a[++n].x=2e18;a[n].y=2e18;
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		printf("%lld %lld\n",a[i].x,a[i].y);
	for(int i=2;i<=n;i++)
		p[i]=p[i-1]+a[i].x-a[i-1].y;//,printf("p[%d]=%lld\n",i,p[i]);
	for(int i=1;i<n;i++)
	{
		int l=i,r=n,m;
		while(l<r)
			if(ok(i,m=(l+r+1)>>1))
				l=m;
			else
				r=m-1;
		//printf("%d %d %lld\n",i,l,a[l].y-a[i].x+h-(p[l]-p[i]));
		ans=max(ans,a[l].y-a[i].x+h-(p[l]-p[i]));
	}
	printf("%lld\n",ans);
	return 0;
}

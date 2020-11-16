#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}

ll cal(ll a,ll b,ll c)
{
	return a*a+b*b+c*c+(ll)7*min(a,min(b,c));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c,d,ans;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		ans=max(cal(a,b,c+d),max(cal(a,b+d,c),cal(a+d,b,c)));
		for(ll i=0;i<=d&&i<=1000;i++) for(ll j=0;i+j<=d&&j<=1000;j++)
			ans=max(ans,cal(a+i,b+j,c+d-i-j));
		printf("%lld\n",ans);
	}
	return 0;
}

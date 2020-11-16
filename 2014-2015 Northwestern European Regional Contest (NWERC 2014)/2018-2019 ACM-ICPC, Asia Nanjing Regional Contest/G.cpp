#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

ll fp(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}

int main()
{
	ll inv=fp(24,mod-2);
	int _;
	scanf("%d",&_);
	while(_--)
	{
		ll x;
		scanf("%lld",&x);
		printf("%lld\n",x*(x+1)%mod*(x+2)%mod*(x+3)%mod*inv%mod);
	}
	return 0;
}

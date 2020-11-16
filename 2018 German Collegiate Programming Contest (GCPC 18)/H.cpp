#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,s;
ll qp(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a*=a)
		if(b&1)
			ans*=a;
	return ans;
}
int main()
{
	scanf("%lld",&m);
	//m=9134731356568979LL;
	ll tt=(ll)(pow(m*3,1.0/3)+0.5);
	for(ll t=max(1LL,tt-5);t<=tt+5;t++)
		if(t*(t+1)*(2*t+1)==6*m)
			return printf("3 %lld\n",t),0;
	for(ll b=3;b<=54;b++)
	{
		ll s=0;
		for(ll a=1;;a++)
		{
			s+=qp(a,b);
			if(s==m)
				return printf("%lld %lld\n",b+1,a),0;
			else if(s>m)
				break;	
		}
	}
	printf("impossible\n");
	return 0;
}

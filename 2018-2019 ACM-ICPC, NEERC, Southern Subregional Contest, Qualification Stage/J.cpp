#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a,b,x,y;
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	ll g=__gcd(x,y);x/=g,y/=g;
	printf("%lld\n",min(a/x,b/y));
	return 0;
}

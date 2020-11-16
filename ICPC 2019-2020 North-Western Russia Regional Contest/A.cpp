#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,n;

int main()
{
	scanf("%lld%lld%lld",&a,&b,&n);
	if(b==n) return puts("1"),0;
	ll ans=1;
	ll rem=n-b;
	ans+=rem/(b-a)*2;
	if(rem%(b-a)!=0) ans+=2;
	printf("%lld",ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,m,x1,y1,x2,y2,ans=0;
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x1,&y1,&x2,&y2);
	if(m&1)
		ans=n-(x2-x1+1);
	if((y1-1)&1)ans+=(x2-x1+1);
	if((m-y2)&1)ans+=(x2-x1+1);
	printf("%lld\n",(ans+1)/2);
	return 0;
}

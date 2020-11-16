#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n1,n2,n3,a1,a2,a3;
void gao()
{
	scanf("%lld%lld%lld%lld%lld%lld",&n1,&n2,&n3,&a1,&a2,&a3);
	for(ll x=1,t;x<(1<<21);x++)
	{
		t=x*x*x;
		if(t%n1==a1&&t%n2==a2&&t%n3==a3)
			return printf("%lld\n",x),void(0);
	}
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)gao();
	return 0;
}
/*
65535 1299709 1299689
1 2 3
*/

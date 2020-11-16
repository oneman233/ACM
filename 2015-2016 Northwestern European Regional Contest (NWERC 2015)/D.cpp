#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll r,p,h[1000006];
ll f(int n)
{
	if(n==1)return 0;
	if(h[n]!=-1)return h[n];
	ll ans=1e18;
	for(int i=2;i<=n;i++)
		ans=min(ans,(i-1)*p+r+f(n/i+(n%i!=0)));
	return h[n]=ans;
}
int main()
{
	memset(h,-1,sizeof(h));
	scanf("%d%lld%lld",&n,&r,&p);
//	for(int i=1;i<=n;i++)
//		printf("%d %lld\n",i,f(i));
	printf("%lld",f(n));
	return 0;
}

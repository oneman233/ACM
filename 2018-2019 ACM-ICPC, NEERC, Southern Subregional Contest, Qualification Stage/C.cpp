#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll ans,a,cnt=2e6;
priority_queue<ll,vector<ll>,greater<ll>>q;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&a);
		q.push(a);
	}
	while(q.size()>1&&cnt)
	{
		ll u=q.top();q.pop();
		ll v=q.top();
		if(u==v)
			q.pop(),q.push(u+u);
		else
			++ans,q.push(u+u);
		--cnt;
	}
	printf("%lld\n",q.size()>1?-1LL:ans);
	return 0;
}

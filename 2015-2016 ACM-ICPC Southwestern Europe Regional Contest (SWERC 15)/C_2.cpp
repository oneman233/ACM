#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> q;
int n;

int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		while(!q.empty()) q.pop();
		ll x,ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&x),q.push(x);
		while(q.size()>=2)
		{
			ll a=q.top();q.pop();
			ll b=q.top();q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		printf("%lld\n",ans);
	}
	return 0;	
}

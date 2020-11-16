#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int n;
ll ans[2005],a[2005],s,t,sum,mx,mm=1llu<<63;
multiset<ll> org,ss;

int main()
{
	scanf("%d%llu%llu",&n,&s,&t);
	for(int i=0;i<n;i++)
		scanf("%llu",a+i),org.insert(a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i&&a[i]==a[i-1]) continue;
		ll now=a[i],cost=0;
		ss=org;
		ss.erase(ss.find(a[i]));
		while(!ss.empty())
		{
			ll nxt=(now+t)%s;
			auto it=ss.lower_bound(nxt);
			if(it==ss.end()) it=ss.begin();
			nxt=*it;
			if((now+t)%s<=nxt) cost+=t+nxt-(now+t)%s;
			else cost+=t+s+nxt-(now+t)%s;
			now=nxt;
			ss.erase(it);
		}
		sum+=(ans[i]=cost+t);
		mm=min(mm,ans[i]),mx=max(mx,ans[i]);
	}
	a[n]=a[0]+s;ans[n]=ans[0];
	for(int i=0;i<n;i++)
	{
		if(a[i+1]<=a[i]+1) continue;
		sum+=ans[i+1]*(a[i+1]-a[i]-1)+(a[i+1]-a[i])*(a[i+1]-a[i]-1)/2;
		mx=max(mx,ans[i+1]+a[i+1]-a[i]-1);
	}
	ll t=__gcd(sum,(unsigned long long)s);
	printf("%llu\n%llu\n",mm,mx);
	//if(sum%s==0)
	//	printf("%llu",sum/t);
	//else
		printf("%llu/%llu",sum/t,s/t);
	return 0;
}

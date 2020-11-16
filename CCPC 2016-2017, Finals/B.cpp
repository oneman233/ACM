#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

int l,n,m;
ll w[100005],d[100005],wash[1000005];
pli t;

void solve(int cs)
{
	ll ans=0;
	priority_queue<pli,vector<pli>,greater<pli>> q;
	scanf("%d%d%d",&l,&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",w+i);
	for(int i=0;i<m;i++) scanf("%lld",d+i);
	sort(w,w+n),sort(d,d+m);
	for(int i=0;i<n;i++) q.emplace(w[i],i);
	for(int i=0;i<l;i++)
	{
		t=q.top();q.pop();
		q.emplace(t.first+w[t.second],t.second);
		wash[i]=t.first;
	}
	while(!q.empty()) q.pop();
	for(int i=0;i<m;i++) q.emplace(d[i],i);
	for(int i=0;i<l;i++)
	{
		t=q.top();q.pop();
		q.emplace(t.first+d[t.second],t.second);
		ans=max(ans,wash[l-i-1]+t.first);
	}
	printf("Case #%d: %lld\n",cs,ans);
}

int main()
{
	int _;
	scanf("%d",&_);
	for(int i=1;i<=_;i++) solve(i);	
	return 0;
}

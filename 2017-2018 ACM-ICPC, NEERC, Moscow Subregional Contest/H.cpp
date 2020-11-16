#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,m,a[100005],b[100005];

ll cal(ll a,ll cnt,int dif)
{
	if(cnt==0) return 0ll;
	if(dif==1) return (a+a+cnt-1)*cnt/2;
	else if(dif==-1)
	{
		cnt=min(cnt,a);
		return (a+a-cnt+1)*cnt/2;
	}
}

bool ok(int id,ll x)
{
	ll L=b[id],R=b[id+1];
//	cout<<"? "<<L<<' '<<R<<endl;
	ll cnt=abs(x-L)+abs(x-R);
	return cnt<=a[id+1]-a[id];
}

ll big(int id,ll l,ll r)
{
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(ok(id,mid)) l=mid+1;
		else r=mid-1;
	}
	return r;
}

ll small(int id,ll l,ll r)
{
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(ok(id,mid)) r=mid-1;
		else l=mid+1;
	}
	return l;
}

void gao()
{
//	cout<<"! "<<ok(1,1)<<' '<<ok(1,3)<<endl;
	ll MAX=0,MIN=0;
	if(m==1)
	{
		MAX=cal(b[1]+1,a[1]-1,1)+cal(b[1]+1,n-a[1],1)+b[1];
		MIN=cal(b[1]-1,a[1]-1,-1)+cal(b[1]-1,n-a[1],-1)+b[1];
		if(MIN<=t&&t<=MAX) puts("Yes");
		else puts("No");
		return;
	}
	MAX+=cal(b[1],a[1],1)+cal(b[m],n-a[m]+1,1);
	MIN+=cal(b[1],a[1],-1)+cal(b[m],n-a[m]+1,-1);
//	cout<<"max: "<<MAX<<" min: "<<MIN<<endl;
	for(int i=1;i<=m-1;++i)
	{
		ll high=big(i,max(b[i],b[i+1]),1e18);
		ll low=small(i,0,min(b[i],b[i+1]));
//		cout<<low<<' '<<high<<endl;
		if(high-b[i]+high-b[i+1]!=a[i+1]-a[i])
			MAX+=cal(b[i],high-b[i]+1,1)+cal(b[i+1],high-b[i+1]+1,1);
		else MAX+=cal(b[i],high-b[i]+1,1)+cal(b[i+1],high-b[i+1]+1,1)-high;
		if(b[i]-low+b[i+1]-low!=a[i+1]-a[i])
			MIN+=cal(low,b[i]-low+1,1)+cal(low,b[i+1]-low+1,1);
		else MIN+=cal(low,b[i]-low+1,1)+cal(low,b[i+1]-low+1,1)-low;
	}
	for(int i=1;i<=m;++i) MAX-=b[i],MIN-=b[i];//
//	cout<<"max: "<<MAX<<" min: "<<MIN<<endl;
	if(MIN<=t&&t<=MAX) puts("Yes");
	else puts("No");
}

int main()
{
	scanf("%lld%lld%lld",&t,&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%lld%lld",&a[i],&b[i]);
	gao();
	return 0;
}
/*
13 5 2
2 2
4 2
*/

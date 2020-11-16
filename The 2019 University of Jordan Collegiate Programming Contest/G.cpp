#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100000;
const ll inf=1e18;

int n;
ll a[N+5],b[N+5];
ll sum[N*4+5],mn[N*4+5];
int cnt[N*4+5],pos=-1;

void up(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
	cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}

void build(int p=1,int l=1,int r=n){
	if(l==r){
		sum[p]=a[l];
		cnt[p]=1;
		mn[p]=b[l];
		return;
	}
	int m=l+r>>1;
	build(p<<1,l,m);
	build(p<<1|1,m+1,r);
	up(p);
}

ll getsum(int L,int R,int p=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return sum[p];
	int m=l+r>>1;
	ll ans=0;
	if(L<=m) ans+=getsum(L,R,p<<1,l,m);
	if(R>m) ans+=getsum(L,R,p<<1|1,m+1,r);
	return ans;
}

int getcnt(int L,int R,int p=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return cnt[p];
	int m=l+r>>1;
	int ans=0;
	if(L<=m) ans+=getcnt(L,R,p<<1,l,m);
	if(R>m) ans+=getcnt(L,R,p<<1|1,m+1,r);
	return ans;
}

int get1(ll x){
	int l=1,r=n,m;
	pos=-1;
	while(l<=r){
		m=l+r>>1;
		if(getsum(1,m)<=x){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	if(ans==-1) return 0;
	else return getcnt(1,ans);
}

ll getmn(int L,int R,int p=1,int l=1,int r=n){
	if(L<=r&&r<=R)
		return mn[p];
	int m=l+r>>1;
	ll ans=inf;
	if(L<=m) ans=min(ans,getmn(L,R,p<<1,l,m));
	if(R>m) ans=min(ans,getmn(L,R,p<<1|1,m+1,r));
	return ans;
}

void modi1(int ix,int p=1,int l=1,int r=n){
	if(l==r&&l==ix){
		sum[p]=a[l];
		cnt[p]=1;
		mn[p]=b[l];
	}
	int m=l+r>>1;
	if(ix<=m) modi1(ix,p<<1,l,m);
	else modi1(ix,p<<1|1,m+1,r);
	up(p);
}

void modi2(int L,int R,int p=1,int l=1,int r=n){
	if(l==r){
		if(getsum(1,l)+b[l]<x){
			a[l]=0;
			b[l]=inf;
			sum[p]=0;
			mn[p]=inf;
			cnt[p]=0;
		}
		return;
	}
	int m=l+r>>1;
	if();
	if();
	up(p);
}

int get2(ll x){
	if(pos==-1) return 0;
	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&a[i],&b[i]);
	build();
	int q;
	scanf("&d",&q);
	while(q--){
		int op;
		ll x,aa,bb;
		scanf("%d",&op);
		if(op==1){
			scanf("%lld",&x);
			int ans1=get1(x);
			int ans2=get2(x);
			printf("%d %d\n",ans1,ans2);
		}
		else if(op==2){
			scanf("%lld%lld%lld",&a,&b,&x);
			
		}
	}
	return 0;
}

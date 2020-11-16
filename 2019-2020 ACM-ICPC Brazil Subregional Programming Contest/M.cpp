#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;

int n,c,t;
int a[N];

bool chk(ll now){
	int cnt=0,sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]>now*t) return 0;
		if(sum+a[i]<=now*t)
			sum+=a[i];
		else{
			cnt++;
			sum=a[i];
		}
	}
	if(sum!=0) cnt++;
	return cnt<=c;
}

ll half(ll l,ll r){
	while(l<=r){
		ll m=(l+r)/2;
		if(chk(m)) r=m-1;
		else l=m+1;
	}
	return l;
}

int main(){
	scanf("%d%d%d",&n,&c,&t);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	ll ans=half(1,1e10);
	printf("%lld",ans);
	return 0;
}

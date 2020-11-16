#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

inline ll exgcd(ll a, ll b, ll &x, ll &y){
	if(!b) return x=1, y=0, a;
	ll g=exgcd(b, a%b, x, y);
	ll z=x; x=y; y=z-a/b*y;
return g;}

inline ll exinv(int a,int P){
	ll x,y;
	if(exgcd(a,P,x,y)!=1) return -1;
	else return (x%P+P)%P;
}

inline ll qpow(ll a,int b,int P){
	ll ans=1;
	for(;b;b>>=1,a=a*a%P)
		if(b&1) ans=ans*a%P;
return ans;}

int bsgs(int a, int b, int p){
	unordered_map<int,int>hsh;
	a%=p, b%=p;
	int s=sqrt(p)+1, bai=b;
	for(int i=0; i<s; ++i) hsh[bai]=i, bai=ll(bai)*a%p;
	int as=qpow(a,s,p);
	if(as==0) return b==0? 1: -1;
	int asi=1;
	for(int i=0; i<=s; ++i){
		int t=hsh.find(asi)==hsh.end()? -1 : hsh[asi];
		if(t>=0&&s*i>=t) return s*i-t;
		asi=ll(asi)*as%p;
	}
	return -1;
}

int exbsgs(int a, int b, int p){
	a%=p, b%=p;
	if(b==1) return 0;
	int k=1, cnt=0, d;
	while((d=__gcd(a,p))!=1){
		if(b%d) return -1;
		p/=d, b/=d, k=ll(a)/d*k%p, ++cnt;
		if(b==k) return cnt;
	}
	int ans=bsgs(a,ll(b)*exinv(k,p)%p,p);
	if(ans>=0) ans+=cnt;
	return ans;
}

inline int solve(){
	int a,b,p;
	cin>>a>>b>>p;
	if(!a && !b && !p) return 0;
	int x=exbsgs(a,b,p);
	if(x==-1) cout<<"No Solution\n";
	else cout<<x<<'\n';
	return 1;
}

signed main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

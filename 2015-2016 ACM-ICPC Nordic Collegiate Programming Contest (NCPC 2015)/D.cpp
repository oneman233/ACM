#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int n,k,t;
int mx[N<<2],tag[N<<2];
int ll(int p){return p*2;}
int rr(int p){return p*2+1;}
int mm(int l,int r){return (l+r)/2;}
int up(int p){mx[p]=max(mx[ll(p)],mx[rr(p)]);}
void down(int p){
	if(tag[p]!=0){
		tag[ll(p)]+=tag[p];
		tag[rr(p)]+=tag[p];
		mx[ll(p)]+=tag[p];
		mx[rr(p)]+=tag[p];
		tag[p]=0;
	}
}
void modi(int L,int R,int p=1,int l=1,int r=N){
	if(L<=l&&r<=R){
		mx[p]++;
		tag[p]++;
		return;
	}
	down(p);
	int m=mm(l,r);
	if(L<=m) modi(L,R,ll(p),l,m);
	if(R>m) modi(L,R,rr(p),m+1,r);
	up(p);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&t),modi(t,t+999);
	int ans=mx[1]/k;
	if(mx[1]%k!=0) ans++;
	printf("%d",ans);
	return 0;
}

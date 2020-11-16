#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 4;
struct Node {
	ll l,r;
	bool operator < (const Node &T) const {
		//if(l!=T.l) return l<T.l;
		return r>T.r;
	}
}pp[maxn];
ll c[maxn];
priority_queue<Node> PQ;
bool cmp(const Node &A,const Node &B){if(A.l!=B.l)return A.l<B.l; return A.r>B.r;}
ll max(ll a,ll b) {return a>b?a:b;}
int main()
{
	ll t,kase=0;
	scanf("%lld",&t);
	while(t--)
	{
		while(!PQ.empty()) PQ.pop();
		ll ans=0,n,m,now=1;
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++) scanf("%lld%lld",&pp[i].l,&pp[i].r);
		sort(pp+1,pp+1+n,cmp);
		for(ll i=1;i<=m;i++) scanf("%lld",&c[i]);
		sort(c+1,c+1+m); 
		for(ll i=1;i<=m;i++) {
			while(c[i]>=pp[now].l) 
			{
				PQ.push(pp[now]); now++;
				if(now>n) break;
				//cout<<"asd ";
			}
			//cout<<"Asd";
			while(!PQ.empty()&&c[i]>PQ.top().r)
			{
				PQ.pop();
				if(PQ.empty()) break; 
				//cout<<"PQ=    "<<PQ.size()<<" ||  ";
				//cout<<"asd ";
			}
		//	cout<<"Adsadsad:    "<<PQ.size()<<endl;
			ll tt=n-(ll)PQ.size()+(ll)1;
			ans=max(ans,tt);
			if(!PQ.empty()) PQ.pop();
		}
		//cout<<"ans=  "<<ans<<endl;
		printf("Case #%lld: ",++kase);
		//prllf("IMPOSSIBLE!\n");			
		if(ans<=n) printf("%lld\n",ans);
		else printf("IMPOSSIBLE!\n");
	}
	return 0;
}
/*
3
3 1
1 4
2 3
5 6
3

*/

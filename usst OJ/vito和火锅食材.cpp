#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=300005;

int s,t;
ll a,sum[maxn],ans=-inf,mx=-inf;
deque<ll> q;

int main(){
	scanf("%d%d",&s,&t);
	for(int i=1;i<=s;++i){
		scanf("%lld",&a);
		mx=max(mx,a);
		sum[i]=sum[i-1]+a;
	}
	q.push_back(0);
	for(int i=1;i<=s;++i){
//		ans=max(ans,sum[i]);
		while(!q.empty()&&sum[i]<sum[q.back()])
			q.pop_back();
		while(!q.empty()&&i-q.front()>t)
			q.pop_front();
		q.push_back(i);
		ans=max(ans,sum[i]-sum[q.front()]);
//		for(int j=0;j<q.size();++j)
//			cout<<q[j]<<' ';cout<<endl;
	}
	if(mx<=0) printf("%lld",mx);
	else printf("%lld",ans);
	return 0;
}
/*
3 3
2 -1 3
*/

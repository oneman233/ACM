#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10005;
typedef long long ll;

int n;
int a[maxn],b[maxn];
bool vis[maxn];
int lk[maxn],rlk[maxn];
vector<ll> v;
vector<int> e[maxn];

bool dfs(int u){
	for(auto v:e[u]){
		if(!vis[v]){
			vis[v]=1;
			if(lk[v]==0||dfs(lk[v])){
				lk[v]=u;
				rlk[u]=v;
				return 1;
			}
		}
	}
	return 0;
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i],&b[i]);
		v.push_back(a[i]+b[i]);
		v.push_back(a[i]-b[i]);
		v.push_back((ll)a[i]*b[i]);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;++i){
		int p=lower_bound(v.begin(),v.end(),a[i]+b[i])-v.begin();
		e[i].push_back(p);
		p=lower_bound(v.begin(),v.end(),a[i]-b[i])-v.begin();
		e[i].push_back(p);
		p=lower_bound(v.begin(),v.end(),(ll)a[i]*b[i])-v.begin();
		e[i].push_back(p);
	}
	bool can=1;
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		if(!dfs(i)){
			can=0;
			break;
		}
	}
	if(!can) puts("impossible");
	else{
		for(int i=1;i<=n;++i){
			char c;
			if(a[i]+b[i]==v[rlk[i]]) c='+';
			else if(a[i]-b[i]==v[rlk[i]]) c='-';
			else if(a[i]*b[i]==v[rlk[i]]) c='*';
			printf("%lld %c %lld = %lld\n",a[i],c,b[i],v[rlk[i]]);
		}
	}
	return 0;
}

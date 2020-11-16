#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;

int n,k,a[maxn];
vector<int> v[maxn],vv[maxn],scc[maxn];
vector<pair<int,int>> save;
char ss[maxn];
int dfn[maxn],low[maxn],timer=0,c[maxn],color=0,cnt[maxn];
bool vis[maxn];
stack<int> s;
int ans=-0x3f3f3f3f;

void tarjan(int x){
	dfn[x]=low[x]=++timer;
	vis[x]=1;
	s.push(x);
	for(auto y:v[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		int t;
		++color;
		while(s.top()!=x){
			t=s.top();
			s.pop();
			c[t]=color;
			scc[color].push_back(t);
			vis[t]=0;
		}
		t=s.top();
		s.pop();
		c[t]=color;
		scc[color].push_back(t);
		vis[t]=0;
	}
}

void build(){
	for(auto x:save){
		if(c[x.first]!=c[x.second]){
			vv[c[x.first]].push_back(c[x.second]);
		}
	}
	for(int i=1;i<=color;++i)
		cnt[i]=scc[i].size();
	cnt[c[0]]--;
}

void dfs(int x,int sum){
	ans=max(ans,sum);
	for(auto y:vv[x])
		dfs(y,sum+cnt[y]);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		v[0].push_back(i);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=n-1;++i){
		if(a[i]>=a[i-1]) v[i].push_back(i-1),save.emplace_back(i,i-1);
		if(a[i]>=a[i+1]) v[i].push_back(i+1),save.emplace_back(i,i+1);	
	}
	if(a[1]>=a[2]) v[1].push_back(2),save.emplace_back(1,2);
	if(a[n]>=a[n-1]) v[n].push_back(n-1),save.emplace_back(n,n-1);
	scanf("%s",ss+1);
	for(int i=1;i<=n;++i)
		if(ss[i]=='T') v[i].push_back(0),save.emplace_back(i,0);
	for(int i=0;i<=n;++i)
		if(!dfn[i]) tarjan(i);
	build();
	dfs(c[k],cnt[c[k]]);
	printf("%d",ans);
	return 0;
}

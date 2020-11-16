#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int n,m,x,y,mp[505][505],now[505][505],deg[505],d[505];
queue<pair<int,int>> init,q;
unordered_map<pair<int,int>,int> cnt;

bool check(int k){
	while(!q.empty()) q.pop();
	q=init;
	for(int i=1;i<=n;++i) d[i]=deg[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			now[i][j]=mp[i][j];
	cnt.clear();
	while(!q.empty()){
		pair<int,int> f=q.front();
		if(cnt[f]>10) break;
		q.pop();
		int x=f.first,y=f.second;
		if(d[x]+d[y]>=k){
			now[x][y]=1;
			now[y][x]=1;
			d[x]++;
			d[y]++;
		}
		else{
			cnt[f]++;
			q.push(f);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(now[i][j]!=1&&i!=j) return 0;
	return 1;
}

int half(int l,int r){
	while(l<r)
	{
		int m=(l+r+1)/2;
		if(check(m)) l=m;
		else r=m-1;
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&x,&y),
		mp[x][y]=1,
		mp[y][x]=1,
		deg[x]++,
		deg[y]++;
	int mx=-inf;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(!mp[i][j]&&!mp[j][i]) init.push(make_pair(i,j)),mx=max(mx,deg[i]+deg[j]);
	int ans=half(0,mx);
	printf("%d",ans);
	return 0;
}

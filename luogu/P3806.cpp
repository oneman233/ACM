#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;

int n,m,a,b,c,ask[maxn];
bool have[maxn*20],can[maxn],vis[maxn];
vector<int> g[maxn],v[maxn];
int sum,sz[maxn],son[maxn],rt;
int rem[maxn],dis[maxn];
queue<int> q;

void getrt(int x,int f){
	sz[x]=1,son[x]=0;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(vis[y]||y==f) continue;
		getrt(y,x);
		sz[x]+=sz[y];
		son[x]=max(son[x],sz[y]);
	}
	son[x]=max(son[x],sum-sz[x]);
	if(son[x]<son[rt]) rt=x;
}

void getdis(int x,int f){
	rem[++rem[0]]=dis[x];
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(vis[y]||y==f) continue;
		dis[y]=dis[x]+v[x][i];
		getdis(y,x);
	}
}

void cal(int x){
	dis[x]=0;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(vis[y]) continue;
		rem[0]=0;//clear the rem every time
		dis[y]=v[x][i];
		getdis(y,x);
		for(int i=rem[0];i;--i){
			for(int j=1;j<=m;++j){
				if(can[j]) continue;
				if(ask[j]>=rem[i])
					can[j]|=have[ask[j]-rem[i]];
			}
		}
		for(int i=rem[0];i;--i){
			have[rem[i]]=1;
			q.push(rem[i]);
		}
	}
	while(!q.empty()){
		int f=q.front();
		have[f]=0;//clear the have[]
		q.pop();
	}
}

void div(int x){
	vis[x]=1,have[0]=1;
	cal(x);
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(vis[y]) continue;
		sum=sz[y];//change the total number of points
		rt=0;
		son[rt]=inf;
		getrt(y,0);
		div(rt);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;++i){
		scanf("%d%d%d",&a,&b,&c);
		g[a].push_back(b);
		g[b].push_back(a);
		v[a].push_back(c);
		v[b].push_back(c);
	}
	for(int i=1;i<=m;++i) scanf("%d",&ask[i]);
	sum=n;
	rt=0;
	son[rt]=inf;
	getrt(1,0);
	div(rt);
	for(int i=1;i<=m;++i){
		if(can[i]) puts("AYE");
		else puts("NAY");
	}
	return 0;
}


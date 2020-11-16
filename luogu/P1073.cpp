#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;
inline int read(){
    char ch=getchar();int s=0,w=1;
    while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}
    while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
    return s*w;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}

int n,m,x[maxn],y[maxn],z;
int mx[maxn],mn[maxn],ans=0,w[maxn];
vector<int> v[maxn],scc[maxn],vv[maxn];
int dfn[maxn],low[maxn],timer=0,c[maxn],color=0;
stack<int> s;
bool vis[maxn],can[maxn];

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
		++color;
		int t;
		while(s.top()!=x){
			t=s.top();
			s.pop();
			vis[t]=0;
			c[t]=color;
			scc[color].push_back(t);
		}
		t=s.top();
		s.pop();
		vis[t]=0;
		c[t]=color;
		scc[color].push_back(t);
	}
}

void build(){
	for(int i=1;i<=m;++i){
		if(c[x[i]]!=c[y[i]]){
			vv[c[x[i]]].push_back(c[y[i]]);
		}
	}
}

bool dfs1(int x){
	if(x==c[n]) {can[x]=1;return 1;}
	if(vis[x]&&can[x]) return 1;
	else if(vis[x]&&!can[x]) return 0;
	vis[x]=1;
	for(auto y:vv[x]){
		if(dfs1(y)) can[x]=1;
	}
	if(can[x]) return 1;
	else return 0;
}

void dfs(int x,int down){
	vis[x]=1;
	down=min(down,mn[x]);
	if(can[x])
	ans=max(ans,mx[x]-down);
	for(auto y:vv[x])
		if(!vis[y]) dfs(y,down);
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) w[i]=read();
	memset(mx,-0x3f,sizeof(mx));
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=m;++i){
		x[i]=read(),y[i]=read(),z=read();
		if(z==1) v[x[i]].push_back(y[i]);
		else v[x[i]].push_back(y[i]),
			v[y[i]].push_back(x[i]);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=color;++i)
		for(auto x:scc[i])
			mx[i]=max(mx[i],w[x]),
			mn[i]=min(mn[i],w[x]);
	build();
	memset(vis,0,sizeof(vis));
	dfs1(c[1]);
	memset(vis,0,sizeof(vis));
	dfs(c[1],inf);
	write(ans);
	return 0;
}

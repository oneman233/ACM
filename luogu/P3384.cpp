#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;

int tg=0,tt=0,td=0;
//tot_graph tot_tree tot_dfs
int head[maxn],e[maxn],to[maxn];
//add
int fa[maxn],sz[maxn],dep[maxn],son[maxn];
//d1
int top[maxn],ord[maxn],rord[maxn],last[maxn]; 
//d2
struct tree{
	int l,r,ls,rs,v,tag;
}tr[maxn];
//build
int n,m,R,P,x,y,z,op,w[maxn];
//main

void add(int x,int y){
	e[++tg]=y;
	to[tg]=head[x];
	head[x]=tg;
}

void d1(int x){
	sz[x]=1;
	for(int i=head[x];i;i=to[i]){
		int y=e[i];
		if(y==fa[x]) continue;
		fa[y]=x;//change y's father
		dep[y]=dep[x]+1;//the depth of x
		d1(y);
		sz[x]+=sz[y];//change x's size
		if(sz[y]>sz[son[x]])
			son[x]=y;//change the heavy son
	}
}

void d2(int x,int t){
	top[x]=t;//the point on the top of heacy chain
	ord[x]=++td;//the dfs order
	rord[td]=x;//which point dfs order refers to
	if(son[x]) d2(son[x],t);
	for(int i=head[x];i;i=to[i]){
		int y=e[i];
		if(y!=fa[x]&&y!=son[x])
			d2(y,y);
	}
	last[x]=td;//modify the nodes under x
}

void up(int p){
	tr[p].v=tr[tr[p].ls].v+tr[tr[p].rs].v;
}
void down(int p){
	if(tr[p].tag!=0){
		tr[tr[p].ls].v+=tr[p].tag*(tr[tr[p].ls].r-tr[tr[p].ls].l+1);
		tr[tr[p].rs].v+=tr[p].tag*(tr[tr[p].rs].r-tr[tr[p].rs].l+1);
		tr[tr[p].ls].tag+=tr[p].tag;
		tr[tr[p].rs].tag+=tr[p].tag;
		tr[p].tag=0;
	}
}
int sum(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y)
		return tr[p].v;
	int ans=0,m=tr[p].l+tr[p].r>>1;
	down(p);
	if(x<=m) ans+=sum(tr[p].ls,x,y);
	ans%=P;
	if(y>m) ans+=sum(tr[p].rs,x,y);
	ans%=P;
	up(p);
	return ans;
}
void modify(int p,int x,int y,int z){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].v+=z*(tr[p].r-tr[p].l+1);
		tr[p].tag+=z;
		return;
	}
	int m=tr[p].l+tr[p].r>>1;
	down(p);
	if(x<=m) modify(tr[p].ls,x,y,z);
	if(y>m) modify(tr[p].rs,x,y,z);
	up(p);
}

void build(int x,int y){
	++tt;
	tr[tt].l=x;
	tr[tt].r=y;
	tr[tt].tag=0;
	if(x==y){
		tr[tt].ls=tr[tt].rs=0;
		tr[tt].v=w[rord[x]];
		return;
	}
	else{
		int tmp=tt,m=x+y>>1;
		tr[tmp].ls=tt+1,build(x,m);
		tr[tmp].rs=tt+1,build(m+1,y);
		up(tmp);
	}
}

void modify_xy(int x,int y,int z){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])
			swap(x,y);
		modify(1,ord[top[y]],ord[y],z);
		//the dfs order of the top point is bigger the the points under it
		y=fa[top[y]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	modify(1,ord[x],ord[y],z);
}
int sum_xy(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])
			swap(x,y);
		ans+=sum(1,ord[top[y]],ord[y]);
		ans%=P;
		y=fa[top[y]];
	}
	if(dep[x]>dep[y]) 
		swap(x,y);
	ans+=sum(1,ord[x],ord[y]);
	ans%=P;
	return ans;
}
void modify_x(int x,int z){
	modify(1,ord[x],last[x],z);
}
int sum_x(int x){
	int ans=sum(1,ord[x],last[x]);
	ans%=P;
	return ans;
}

signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&R,&P);
	for(int i=1;i<=n;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n-1;++i){
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	d1(R);
	d2(R,R);
	build(1,n);
	for(int i=1;i<=m;++i){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&z);
			modify_xy(x,y,z);
		}
		else if(op==2){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",sum_xy(x,y));
		}
		else if(op==3){
			scanf("%lld%lld",&x,&z);
			modify_x(x,z);
		}
		else if(op==4){
			scanf("%lld",&x);
			printf("%lld\n",sum_x(x));
		}
	}
	return 0;
}

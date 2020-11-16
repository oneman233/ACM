#include <bits/stdc++.h>
using namespace std;
const int MN=100005;
typedef long long ll;

int n,m;
bool v[MN];
vector<int> to[MN],rto[MN],val[MN],rval[MN];
ll dst1[MN],dst2[MN];
void add(int x,int y,int z){
	to[x].push_back(y);
	val[x].push_back(z);
	rto[y].push_back(x);
	rval[y].push_back(z);
}
void dij(ll dst[],int src,vector<int>to[],vector<int>val[]){
	memset(dst,0x3f,sizeof(int)*MN);
	dst[src]=0;
	memset(v,0,sizeof(v));
	priority_queue<pair<ll,int>>q;
	q.push({0,src});
	int sz=to[src].size();
	for(int i=0;i<sz;++i){
		int y=to[src][i], z=val[src][i];
		dst[y]=z;
		q.push({-dst[y],y});
	}
	while(q.size()){
		int x=q.top().second; q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=0;i<to[x].size();++i){
			int y=to[x][i], z=val[x][i];
			if(dst[y]>dst[x]+z){
				dst[y]=dst[x]+z;
				q.push({-dst[y],y});
			}
		}
	}
}
void dij1(ll dst[]=dst1,int src=1){
	memset(dst,0x3f3f,sizeof(ll)*MN);
	dst[src]=0;
	memset(v,0,sizeof(v));
	priority_queue<pair<ll,int>>q;
	q.push({0,src});
	int sz=to[src].size();
	for(int i=0;i<sz;++i){
		int y=to[src][i], z=val[src][i];
		dst[y]=z;
		q.push({-dst[y],y});
	}
	while(q.size()){
		int x=q.top().second; q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=0;i<to[x].size();++i){
			int y=to[x][i], z=val[x][i];
			if(dst[y]>dst[x]+z){
				dst[y]=dst[x]+z;
				q.push({-dst[y],y});
			}
		}
	}
}
void dij2(ll dst[]=dst2,int src=2,vector<int> to[]=rto,vector<int> val[]=rval){
	memset(dst,0x3f3f,sizeof(ll)*MN);
	dst[src]=0;
	memset(v,0,sizeof(v));
	priority_queue<pair<ll,int>>q;
	q.push({0,src});
	int sz=to[src].size();
	for(int i=0;i<sz;++i){
		int y=to[src][i], z=val[src][i];
		dst[y]=z;
		q.push({-dst[y],y});
	}
	while(q.size()){
		int x=q.top().second; q.pop();
//printf("dij2: %d\n",x);
		if(v[x])continue;
		v[x]=1;
		for(int i=0;i<to[x].size();++i){
			int y=to[x][i], z=val[x][i];
			if(dst[y]>dst[x]+z){
				dst[y]=dst[x]+z;
				q.push({-dst[y],y});
			}
		}
	}
}
int x[MN],y[MN],z[MN];
vector<int> nto[MN],nval[MN];
void nadd(int x,int y,int z){
	nto[x].push_back(y);
	nval[x].push_back(z);
}
int dfn[MN],low[MN],num;
map<pair<pair<int,int>,int>,bool>bridge;
void tarjan(int x,int fa){
	low[x]=dfn[x]=++num;
	for(int i=0;i<nto[x].size();++i){
		int y=nto[x][i], z=nval[x][i];
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]) bridge[{{x,y},z}]=bridge[{{y,x},z}]=1; 
		}else if(y!=fa) low[x]=min(low[x],dfn[y]);
	}
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d%d",x+i,y+i,z+i);
		add(x[i],y[i],z[i]);
	}
	dij1(); dij2();
//	dij(dst1,1,to,val);
//	dij(dst2,2,rto,rval);
//for(int i=1;i<=n;++i) printf("%d\td1:%lld\td2:%lld\n",i,dst1[i],dst2[i]);
	ll md=dst1[2];
	for(int i=0;i<m;++i)
		if(dst1[x[i]]+z[i]+dst2[y[i]]==md)
//printf("qaq %d~%d\n",x[i],y[i]),
			nadd(x[i],y[i],z[i]), nadd(y[i],x[i],z[i]);
	for(int i=1;i<=n;++i)
		if(!dfn[i])
			tarjan(i,0);
//for(int x=1;x<=n;++x) for(int y=1;y<=n;++y) printf("%d~%d:%d\n",x,y,bridge[{x,y}]);
//for(int i=0;i<m;++i) printf("%d~%d:%d\n",x[i],y[i],bridge[{x[i],y[i]}]);
	for(int i=0;i<m;++i){
		ll md2=dst1[y[i]]+z[i]+dst2[x[i]];
//printf("%lld %lld\n",md,md2);
		if(md2<md) puts("HAPPY");
		else if(md==md2) puts("SOSO");
		else if(bridge[{{x[i],y[i]},z[i]}])puts("SAD");
		else puts("SOSO");
	}
	return 0;
}

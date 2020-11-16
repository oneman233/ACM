#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,k;
int f[N],dep[N],len[N],son[N],top[N];
vector<int> e[N];
vector<int> tmp;

void d1(int x){
	len[x]=1;
	for(auto y:e[x]){
		dep[y]=dep[x]+1;
		d1(y);
		len[x]=max(len[x],len[y]+1);
		if(len[y]>len[son[x]]) son[x]=y;
	}
}

void d2(int x,int t){
	top[x]=t;
	if(e[x].size()==0){
		tmp.push_back(dep[x]-dep[top[x]]+1);
		return;
	}
	if(son[x]) d2(son[x],t);
	for(auto y:e[x]){
		if(y!=son[x]) d2(y,y);
	}
}

void gao(){
	int leaf=0;
	for(int i=1;i<=n;++i)
		if(e[i].size()==0) leaf++;
	if(k>=leaf){
		printf("%d",n);
		return;
	}
	dep[1]=1;
	d1(1);
	d2(1,1);
	sort(tmp.begin(),tmp.end(),greater<int>());
	int ans=0;
	for(int i=0;i<k;++i) ans+=tmp[i];
	printf("%d",ans);
}

int main(){
	scanf("%d%d",&n,&k);
	f[1]=0;
	for(int i=2;i<=n;++i)
		scanf("%d",&f[i]),e[f[i]].push_back(i);
	gao();
	return 0;
}
/*
9 2
1 1 3 2 5 6 7 7
*/

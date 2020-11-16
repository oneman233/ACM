#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;

int n,m,l,r,k;
int a[maxn],tmp[maxn],org[maxn],tot=0;
struct node{
	int ll,rr,cnt;
}tr[maxn*300];
int rt[maxn];

int build(int l,int r){
	int p=++tot;
	tr[p].cnt=0;
	if(l==r) return p;
	int m=l+r>>1;
	tr[p].ll=build(l,m);
	tr[p].rr=build(m+1,r);
	return p;
}

int change(int rt,int l,int r,int x,int y){
	int p=++tot;
	tr[p]=tr[rt];
	if(l==r){
		tr[p].cnt++;
		return p;
	}
	int m=l+r>>1;
	if(y<=m) tr[p].ll=change(tr[rt].ll,l,m,x,y);
	else tr[p].rr=change(tr[rt].rr,m+1,r,x,y);//rebuild
	tr[p].cnt=tr[tr[p].ll].cnt+tr[tr[p].rr].cnt;//up
	return p;
}

int ask(int p,int q,int l,int r,int k){
	int sum=tr[tr[q].ll].cnt-tr[tr[p].ll].cnt;
	int m=l+r>>1;
	if(l==r) return l;
	if(sum>=k) return ask(tr[p].ll,tr[q].ll,l,m,k);
	else return ask(tr[p].rr,tr[q].rr,m+1,r,k-sum);
}

int main(){
	scanf("%d%d",&n,&m);
	rt[0]=build(1,n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		tmp[i]=a[i];
	}
	sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;++i){
		int k=lower_bound(tmp+1,tmp+1+n,a[i])-tmp;
		org[k]=a[i],a[i]=k;
	}
	for(int i=1;i<=n;++i)
		rt[i]=change(rt[i-1],1,n,1,a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",org[ask(rt[l-1],rt[r],1,n,k)]);
	}
	return 0;
}

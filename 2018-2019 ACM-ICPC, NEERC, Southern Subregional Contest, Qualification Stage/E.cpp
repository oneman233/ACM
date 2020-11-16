#include <bits/stdc++.h>
using namespace std;

int n,q,a[300005],seg[300005<<2],lazy[300005<<2];
deque<int> Q[300005];

void build(int rt,int l,int r)
{
	if(l==r)
	{
		lazy[rt]=0;
		seg[rt]=a[l];
		return;
	}
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}

inline void pushdown(int rt)
{
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	seg[rt<<1]=seg[rt<<1|1]=lazy[rt];
	lazy[rt]=0;
}

void modify(int rt,int l,int r,int L,int R,int col)
{
	if(L<=l&&r<=R)
	{
		lazy[rt]=seg[rt]=col;
		return;
	}
	if(lazy[rt]) pushdown(rt);
	int m=l+r>>1;
	if(L<=m) modify(rt<<1,l,m,L,R,col);
	if(m<R) modify(rt<<1|1,m+1,r,L,R,col);
}

int query(int rt,int l,int r,int x)
{
	if(l==r) return seg[rt];
	if(lazy[rt]) pushdown(rt);
	int m=l+r>>1;
	if(x<=m) return query(rt<<1,l,m,x);
	return query(rt<<1|1,m+1,r,x);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),Q[a[i]].push_back(i);
	build(1,1,n);
	scanf("%d",&q);
	while(q--)
	{
		int x,l,r;
		scanf("%d",&x);
		while(!Q[x].empty()&&query(1,1,n,Q[x].front())!=x) Q[x].pop_front();
		while(!Q[x].empty()&&query(1,1,n,Q[x].back())!=x) Q[x].pop_back();
		if(Q[x].empty()) continue;
		l=Q[x].front(),r=Q[x].back();
		modify(1,1,n,l,r,x);
	}
	for(int i=1;i<=n;i++) printf("%d ",query(1,1,n,i));
	return 0;
}

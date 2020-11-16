#include <bits/stdc++.h>
using namespace std;
const int N=100005;

typedef pair<int,int>pii;
bool ed[N];
int n,k,ans,x[100005],y[100005],seg[200005<<2],lazy[200005<<2];
multiset<int> q;
vector<pii> vv;
vector<int> v;

bool cmp(pii l,pii r)
{
	return l.second==r.second? l.first<r.first: l.second<r.second;
}

inline void pushdown(int rt)
{
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	seg[rt<<1]+=lazy[rt];
	seg[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}

void modify(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) 
	{
		seg[rt]++;
		lazy[rt]++;
		return;
	}
	int m=l+r>>1;
	if(lazy[rt]) pushdown(rt);
	if(L<=m) modify(rt<<1,l,m,L,R);
	if(m<R) modify(rt<<1|1,m+1,r,L,R);
	seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return seg[rt];
	int m=l+r>>1,ret=0;
	if(lazy[rt]) pushdown(rt);
	if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
	if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
	return ret;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&x[i],&y[i]),y[i]--,v.push_back(x[i]),v.push_back(y[i]);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
		x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1,
		y[i]=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
	for(int i=1;i<=n;i++)
		vv.emplace_back(x[i],y[i]);
	sort(vv.begin(),vv.end(),cmp);
	int N=v.size();
	for(auto p:vv)
	{
		//printf("!! %d\n",query(1,1,N,p.first,p.second));
		if(query(1,1,N,p.first,p.second)<k) ans++,modify(1,1,N,p.first,p.second);
	}
	printf("%d",ans);
	return 0;	
}

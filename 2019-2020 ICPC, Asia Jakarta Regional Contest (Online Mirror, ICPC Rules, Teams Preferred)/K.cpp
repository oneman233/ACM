#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
int n,q,lazy[100005<<2];
ll seg[100005<<2][2][2],ret[2][2];
char s[100005];

void build(int rt,int l,int r)
{
	if(l==r)
	{
		if(s[l]=='A') seg[rt][0][0]=seg[rt][0][1]=seg[rt][1][1]=1;
		else seg[rt][0][0]=seg[rt][1][0]=seg[rt][1][1]=1;
		return;
	}
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	memset(seg[rt],0,sizeof(seg[rt]));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				seg[rt][i][j]+=seg[rt<<1|1][i][k]*seg[rt<<1][k][j]%mod,seg[rt][i][j]%=mod;
}

inline void pushdown(int rt)
{
	if(!lazy[rt]) return;
	lazy[rt<<1]^=1,lazy[rt<<1|1]^=1;
	swap(seg[rt<<1][0][0],seg[rt<<1][1][0]);
	swap(seg[rt<<1][0][1],seg[rt<<1][1][1]);
	swap(seg[rt<<1][0][0],seg[rt<<1][0][1]);
	swap(seg[rt<<1][1][0],seg[rt<<1][1][1]);		
	swap(seg[rt<<1|1][0][0],seg[rt<<1|1][1][0]);
	swap(seg[rt<<1|1][0][1],seg[rt<<1|1][1][1]);
	swap(seg[rt<<1|1][0][0],seg[rt<<1|1][0][1]);
	swap(seg[rt<<1|1][1][0],seg[rt<<1|1][1][1]);
	lazy[rt]=0;
}

void modify(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		lazy[rt]^=1;
		swap(seg[rt][0][0],seg[rt][1][0]);
		swap(seg[rt][0][1],seg[rt][1][1]);
		swap(seg[rt][0][0],seg[rt][0][1]);
		swap(seg[rt][1][0],seg[rt][1][1]);
		return;	
	}
	pushdown(rt);
	int m=l+r>>1;
	if(L<=m) modify(rt<<1,l,m,L,R);
	if(m<R) modify(rt<<1|1,m+1,r,L,R);
	memset(seg[rt],0,sizeof(seg[rt]));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				seg[rt][i][j]+=seg[rt<<1|1][i][k]*seg[rt<<1][k][j]%mod,seg[rt][i][j]%=mod;
}

void query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		ll tmp[2][2];
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					tmp[i][j]+=seg[rt][i][k]*ret[k][j]%mod,tmp[i][j]%=mod;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				ret[i][j]=tmp[i][j];
//		for(int i=0;i<2;i++)
//			for(int j=0;j<2;j++)
//				printf("%lld%c",seg[rt][i][j]," \n"[j==1]);
		return;	
	}
	pushdown(rt);
	int m=l+r>>1;
	if(L<=m) query(rt<<1,l,m,L,R);
	if(m<R) query(rt<<1|1,m+1,r,L,R);
}

int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	build(1,1,n);
	while(q--)
	{
		int op,l,r;
		ll a,b;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) modify(1,1,n,l,r);
		else 
		{
			memset(ret,0,sizeof(ret));ret[0][0]=ret[1][1]=1;
			scanf("%lld%lld",&a,&b);
			query(1,1,n,l,r);
			printf("%lld %lld\n",(ret[0][0]*a%mod+ret[0][1]*b%mod)%mod,(ret[1][0]*a%mod+ret[1][1]*b%mod)%mod);
		}
	}
	return 0;
}

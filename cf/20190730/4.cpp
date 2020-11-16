#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof(a))
using namespace std;

typedef long long ll;

const int MN = 2e5 + 5;

int a[MN];
struct ST{
	int l,r;
	int m,M;	//最小值，次小值
	int cntm;	//最小值的数量
	ll sum;		//区间和
}t[MN*4];

inline void changeX(int p,int x){	//把结点p的区间小于x的值改成x
	t[p].sum-= (ll)(t[p].m-x)* t[p].cntm;
	t[p].m= x;
}
inline void down(int p){	//将p结点最小值change成x的懒标向下传
	int pl= p<<1;
	if(t[pl].m < t[p].m)
		changeX(pl,t[p].m);
	int pr= pl|1;
	if(t[pr].m < t[p].m)
		changeX(pr,t[p].m);
}
inline void upTo(int p){	//将p结点的子结点的变化更新到p
	int pl= p<<1;
	int pr= pl|1;
	t[p].sum= t[pl].sum+ t[pr].sum;
	if(t[pl].m == t[pr].m){	//左右子区间最小值一样小的特殊情况
		t[p].m= t[pl].m;
		t[p].cntm= t[pl].cntm+ t[pr].cntm;
		t[p].M= max(t[pl].M,t[pr].M);
	}else{
		if(t[pl].m > t[pr].m)
			swap(pl,pr);	//接下来三行建立在pl的最小值更小的前提下
		t[p].m= t[pl].m;
		t[p].cntm= t[pl].cntm;
		t[p].M= max(t[pl].M,t[pr].m);	//较小最小值区间的次小值和较大最小值
	}
}
void build(int p,int l,int r){
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].sum= t[p].m= a[l];
		t[p].cntm= 1;
		t[p].M= (1e9 + 5);	//正无穷
		//cout<<"!built"<<l<<"~"<<r<<" M:"<<t[p].ml<<"~"<<t[p].mr<<'\n';
		return;
	}
	int mid= l+r >>1;
	int pl= p<<1;
	int pr= pl|1;
	build(pl, l, mid);
	build(pr, mid+1, r);
	upTo(p);
//	//cout<<"built"<<l<<"~"<<r<<" M:"<<t[p].ml<<"~"<<t[p].mr<<'\n';
}
void change1(int p,int l,int x){	//把a[l]改成x
//cout<<"changing1"<<l<<"~"<<r<<" in t:"<<t[p].l<<"~"<<t[p].r<<": "<<t[p].sum<<'\n';
	if(t[p].l==l && t[p].r==l){
		t[p].sum= t[p].m= x;
		t[p].cntm= 1;
		t[p].M= (1e9 + 5);	//正无穷
		return;
	}
	down(p);	//把之前的m懒标往下传
	int mid= t[p].l+t[p].r >>1;
	if(l<=mid)
		change1(p<<1, l, x);
	if(mid<l)
		change1(p<<1|1, l, x);
	upTo(p);
}
void change2(int p,int l,int r,int x){	//把[l,r]区间最小值改成x
//cout<<"changing2"<<l<<"~"<<r<<" in t:"<<t[p].l<<"~"<<t[p].r<<": "<<t[p].sum<<'\n';
	if(x<=t[p].m)	//不用改啦
		return;
	if(t[p].l>=l && t[p].r<=r && x<t[p].M){	//在最小值次小值之间时才能用懒标
		changeX(p,x);	//懒惰修改，不下传
		return;
	}
	down(p);	//把之前的m懒标往下传
	int mid= t[p].l+t[p].r >>1;
	if(l<=mid)
		change2(p<<1, l, r, x);
	if(mid<r)
		change2(p<<1|1, l, r, x);
	upTo(p);
}

ll ask(int p,int l,int r){	//返回[l,r]区间和
//cout<<"asking"<<l<<"~"<<r<<" in t:"<<t[p].l<<"~"<<t[p].r<<": "<<t[p].sum<<'\n';
	if(t[p].l>=l && t[p].r<=r)	//被完全覆盖
		return t[p].sum;
	down(p);	//记得先传懒标！！
	ll rt= 0;
	int mid= t[p].l+ t[p].r >>1;
	if(mid>=l)		//需要取左
		rt+= ask(p<<1, l, r);
	if(mid<r)	//需要取右
		rt+= ask(p<<1|1, l, r);
	return rt;
}

int main(int argc, char *argv[]) {
	int n,q;
	scanf("%d",&n);
	for__(i,1,n)
		scanf("%d",a+i);
	build(1,1,n);

	scanf("%d",&q);
	int op,p,x;
	while(q--){
		scanf("%d%d",&op,&p);
		if(op==1)
			scanf("%d",&x),
			change1(1,p,x);
		else
			change2(1,1,n,p);
	}
	for__(i,1,n)
		printf("%lld%c",ask(1,i,i)," \n"[i==n]);
	return 0;
}

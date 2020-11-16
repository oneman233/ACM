#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define schar(a) scanf("%c",&a)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define re(i,a,b) for(int i=a;i<=b;++i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define prn() printf("\n")
#define prs() printf(" ")
#define mkp make_pair
#define pii pair<int,int>
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst first
#define snd second
#define frt front()
#define bak back()
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define debug
#define db double
#define yyes cout<<"YES"<<endl;
#define nno cout<<"NO"<<endl;
using namespace std;
typedef vector<int> vei;
typedef vector<pii> vep;
typedef map<int,int> mpii;
typedef map<char,int> mpci;
typedef map<string,int> mpsi;
typedef deque<int> deqi;
typedef deque<char> deqc;
typedef priority_queue<int> mxpq;
typedef priority_queue<int,vector<int>,greater<int> > mnpq;
typedef priority_queue<pii> mxpqii;
typedef priority_queue<pii,vector<pii>,greater<pii> > mnpqii;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=100000007;
const db eps=1e-10;
int qpow(int a,int b){int tmp=a%MOD,ans=1;while(b){if(b&1){ans*=tmp,ans%=MOD;}tmp*=tmp,tmp%=MOD,b>>=1;}return ans;}
int lowbit(int x){return x&-x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int mmax(int a,int b,int c){return max(a,max(b,c));}
int mmin(int a,int b,int c){return min(a,min(b,c));}
void mod(int &a){a+=MOD;a%=MOD;}
bool chk(int now){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){if(x==0) return 1;return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

int n,m,op,l,r,k,x;
int a[maxn],mx[maxn*20],sum[maxn*20];

void up(int p){
	mx[p]=max(mx[ll(p)],mx[rr(p)]);
	sum[p]=sum[ll(p)]+sum[rr(p)];
}

void build(int p,int l,int r){
	if(l==r){
		sum[p]=mx[p]=a[l];
		return;
	}
	int m=mm(l,r);
	build(ll(p),l,m);
	build(rr(p),m+1,r);
	up(p);
}

void setx(int p,int l,int r,int k,int x){
	if(l==r&&l==k){
		mx[p]=sum[p]=x;
		return;
	}
	int m=mm(l,r);
	if(k<=m) setx(ll(p),l,m,k,x);
	else setx(rr(p),m+1,r,k,x);
	up(p);
}

void modx(int p,int l,int r,int L,int R,int x){
	if(mx[p]<x) return;
	if(l==r){
		sum[p]%=x;
		mx[p]%=x;
		return;
	}
	int m=mm(l,r);
	if(L<=m) modx(ll(p),l,m,L,R,x);
	if(R>m) modx(rr(p),m+1,r,L,R,x);
	up(p);
}

int ask(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R)
		return sum[p];
	int m=mm(l,r),res=0;
	if(L<=m) res+=ask(ll(p),l,m,L,R);
	if(R>m) res+=ask(rr(p),m+1,r,L,R);
	return res;
}

signed main(){
    scc(n,m);
    re(i,1,n) sc(a[i]);
    build(1,1,n);
    re(i,1,m){
		sc(op);
		if(op==1) scc(l,r),pr(ask(1,1,n,l,r)),prn();
		else if(op==2) sccc(l,r,x),modx(1,1,n,l,r,x);
		else if(op==3) scc(k,x),setx(1,1,n,k,x);
	}
    return 0;
}
/*
5 100
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3
*/

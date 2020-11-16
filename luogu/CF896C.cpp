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
typedef vector<int> vec;
typedef map<int,int> mpii;
typedef deque<int> deq;
typedef priority_queue<int> mxpq;
typedef priority_queue<int,vector<int>,greater<int> > mnpq;
typedef priority_queue<pii> mxpqii;
typedef priority_queue<pii,vector<pii>,greater<pii> > mnpqii;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
int MOD=100000007;
const db eps=1e-10;
int qpow(int a,int b){int tmp=a%MOD,ans=1;while(b){if(b&1){ans*=tmp,ans%=MOD;}tmp*=tmp,tmp%=MOD,b>>=1;}return ans;}
int lowbit(int x){return x&-x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int mmax(int a,int b,int c){return max(a,max(b,c));}
int mmin(int a,int b,int c){return min(a,min(b,c));}
void mod(int &a){a+=MOD;a%=MOD;}
bool chk(int cost){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

int n,m,seed,vmax,a[maxn];

int rnd(){
	int ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}

struct node{
	int l,r;
	mutable int v;
	node(int L,int R=-1,int V=0):l(L),r(R),v(V){}
	bool operator < (const node& tmp) const{return l<tmp.l;}
};
set<node> s;
typedef set<node>::iterator IT;

IT split(int pos){
	IT it=s.lower_bound(node(pos));
	if(it!=s.end()&&it->l==pos) return it;
	--it;
	int L=it->l,R=it->r,V=it->v;
	s.erase(it);
	s.insert(node(L,pos-1,V));
	return s.insert(node(pos,R,V)).fst;
}

void add(int l,int r,int val){
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;++itl) itl->v+=val;
}

void assign(int l,int r,int v){
	IT itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,v));
}

int rk(int l,int r,int k){
	IT itr=split(r+1),itl=split(l);
	vector<pii> v;
	for(;itl!=itr;++itl) v.pub(mkp(itl->v,itl->r-itl->l+1));
	sort(v.begin(),v.end());
	fo(i,0,v.size()){
		k-=v[i].snd;
		if(k<=0) return v[i].fst;
	}
	return -1;
}

int sum(int l,int r,int ex,int mm){
	IT itr=split(r+1),itl=split(l);
	int res=0;
	MOD=mm;
	for(;itl!=itr;++itl){
		res+=((itl->r-itl->l+1)%MOD*qpow(itl->v,ex)%MOD)%MOD;
		res%=MOD;
	}
	return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sccc(n,m,seed),sc(vmax);
    re(i,1,n){
    	a[i]=(rnd()%vmax)+1;
    	s.insert(node(i,i,a[i]));
	}
	re(i,1,m){
		int op=(rnd()%4)+1;
		int l=(rnd()%n)+1;
		int r=(rnd()%n)+1;
		if(l>r) swap(l,r);
		int x,y;
		if(op==3) x=(rnd()%(r-l+1))+1;
		else x=(rnd()%vmax)+1;
		if(op==4) y=(rnd()%vmax)+1;
		if(op==1){
			add(l,r,x);
		}
		else if(op==2){
			assign(l,r,x);
		}
		else if(op==3){
			pr(rk(l,r,x)),prn();
		}
		else if(op==4){
			pr(sum(l,r,x,y)),prn();
		}
	}
    return 0;
}

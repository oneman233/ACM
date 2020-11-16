#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define scs(a) scanf("%s",a) 
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
#define nmsl cout<<"NMSL"<<endl;
#define all(i,a) for(auto i=a.begin();i!=a.end();++i)
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
const int maxn=1005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=100000007;
const db eps=1e-10;
const db pi=3.1415926535;
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
bool bigeql(db a,db b){if(a>b||fabs(a-b)<=eps)return true;return false;}
bool eql(db a,db b){if(fabs(a-b)<eps) return 1;return 0;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}
inline int read(){
    char ch=getchar();int s=0,w=1;
    while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}
    while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
    return s*w;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	if(!(a&1)&&!(b&1)) return gcd(a>>1,b>>1)<<1;
	else if(!(b&1)) return gcd(a,b>>1);
	else if(!(a&1)) return gcd(a>>1,b);
	else return gcd(abs(a-b),min(a,b));
}
int lcm(int x,int y){return x*y/gcd(x,y);}

int n,m;
vei e[maxn];
vep v;
int f[maxn],dia[maxn],mid[maxn],last=0,mx=-inf;

int _find(int x){
	if(x!=f[x]) f[x]=_find(f[x]);
	return f[x];
}

void _merge(int x,int y){
	x=_find(x),y=_find(y);
	if(x!=y) f[x]=y;
}

void dfs(int x,int f,int d){
	if(d>mx){
		mx=d;
		last=x;
	}
	for(auto y:e[x]){
		if(y==f) continue;
		dfs(y,x,d+1);
	}
}

void seek(int x,int f,int d){
	if(mid[_find(x)]) return;
	if(d==dia[_find(x)]/2){
		mid[_find(x)]=x;
		return;
	}
	for(auto y:e[x])
		seek(y,x,d+1);
}

void pre(){
	re(i,1,n){
		if(mid[_find(i)]!=0) continue;
		last=0,mx=-inf;
		dfs(i,i,0);
		dfs(last,last,0);
		dia[_find(i)]=mx;
		seek(last,last,0);
	}
}

void gao(){
	re(i,1,n){
		re(j,1,n){
			if(_find(i)==_find(j)) continue;
			e[mid[_find(i)]].pub(mid[_find(j)]),
			e[mid[_find(j)]].pub(mid[_find(i)]);
			v.pub(mkp(mid[_find(i)],mid[_find(j)]));
			_merge(_find(i),_find(j));
			last=0,mx=-inf;
			mid[_find(i)]=0;
			dfs(i,i,0);
			dfs(last,last,0);
			dia[_find(i)]=mx;
			seek(last,last,0);
		}
	}
	cout<<dia[_find(1)]<<endl;
	for(auto i:v) cout<<i.fst<<' '<<i.snd<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,n) f[i]=i;
    re(i,1,m){
		int x,y;
		cin>>x>>y;
		e[x].pub(y);
		e[y].pub(x);
		_merge(x,y);
	}
	pre();
	gao();
    return 0;
}
/*
9 7
1 2
1 3
2 4
3 6
3 5
3 7
8 9
*/

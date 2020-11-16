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
int gcd(int a, int b)
{
	if(a == 0) return b;
	if(b == 0) return a;
	if(!(a & 1) && !(b & 1))
		return gcd(a >> 1, b >> 1) << 1;
	else if(!(b & 1))
		return gcd(a, b >> 1);
	else if(!(a & 1))
		return gcd(a >> 1, b);
	else
		return gcd(abs(a - b), min(a, b));
}
int lcm(int x,int y){return x*y/gcd(x,y);}

int n,m;
char ss[maxn];

struct node{
	int l,r;
	char v;
	node(int L,int R=-1,char V='#'):l(L),r(R),v(V){}
	bool operator < (const node& o)const{return l<o.l;}
};
set<node> s;
typedef set<node>::iterator it;

it split(int pos){
	it i=s.lower_bound(node(pos));
	if(i!=s.end()&&i->l==pos) return i;
	--i;
	int L=i->l,R=i->r;
	char V=i->v;
	s.erase(i);
	s.insert(node(L,pos-1,V));
	return s.insert(node(pos,R,V)).fst;
}

int ask(int x,int y,char k){
	it ir=split(y+1),il=split(x);
	int res=0;
	for(;il!=ir;++il) if(il->v==k) res+=il->r-il->l+1;
	return res;
}

void assign(int x,int y,char k){
	it ir=split(y+1),il=split(x);
	s.erase(il,ir);
	s.insert(node(x,y,k));
}

void _sort(int x,int y){
	it ir=split(y+1),il=split(x);
	int cnt[26];
	mem0(cnt);
	for(it i=il;i!=ir;++i) cnt[(i->v)-'A']+=i->r-i->l+1;
	s.erase(il,ir);
	int now=x;
	fo(i,0,26){
		if(cnt[i]!=0){
			s.insert(node(now,now+cnt[i]-1,i+'A'));
			now+=cnt[i];
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    n=read(),m=read();
    scanf("%s",ss+1);
    re(i,1,n) ss[i]=toupper(ss[i]),s.insert(node(i,i,ss[i]));
    while(m--){
		int op=read();
		int x,y;
		char k;
		if(op==1){
			x=read(),y=read();
			scanf("%c",&k);
			k=toupper(k);
			write(ask(x,y,k)),prn();
		}
		else if(op==2){
			x=read(),y=read();
			scanf("%c",&k);
			k=toupper(k);
			assign(x,y,k);
		}
		else{
			x=read(),y=read();
			_sort(x,y);
		}
	}
    return 0;
}

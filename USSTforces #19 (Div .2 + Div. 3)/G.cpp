#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define scs(a) scanf("%s",a) 
#define schar(a) scanf("%c",&a)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(register int i=a;i<b;++i)
#define re(i,a,b) for(register int i=a;i<=b;++i)
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
const int maxn=1000005;
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
char c[1005][1005];
struct node{
	int x,y,r;
	node(){}
	node(int xx,int yy,int rr):x(xx),y(yy),r(rr){}
}ans[maxn];
int tot=0;
bool del[1005][1005];

bool ok(pii p){
	int i=p.fst;
	int j=p.snd;
	if(i<1||i>n||j<1||j>m||c[i][j]=='.') return 0;
	return 1;
}

void tag(pii p){
	del[p.fst][p.second]=1;
}

void up(pii &p){
	p.fst--;
}

void left(pii &p){
	p.snd--;
}

void right(pii &p){
	p.snd++;
}

void down(pii &p){
	p.fst++;
}

bool isdel(pii p){
	return del[p.fst][p.snd];
}

char s[maxn];

signed main(){
//	freopen("in.txt","r",stdin);
    n=read(),m=read();
    re(i,1,n){
		scanf("%s",s+1);
		re(j,1,m) c[i][j]=s[j];
	}
    re(i,1,n){
		re(j,1,m){
			if(c[i][j]=='*'){
				pii u(i-1,j);
				pii l(i,j-1);
				pii r(i,j+1);
				pii d(i+1,j);
				int L=0;
				while(ok(u)&&ok(l)&&ok(r)&&ok(d)){
//					if(isdel(u)&&isdel(l)&&isdel(r)&&isdel(d)) break;
					tag(u),tag(l),tag(r),tag(d);
					up(u),left(l),right(r),down(d);
					L++;
				}
				if(L!=0){
					tag(pii(i,j));
					tot++;
					ans[tot]=node(i,j,L);
				}
//				cout<<"? "<<i<<' '<<j<<' '<<del[i][j]<<endl;
			}
		}
	}
	bool can=1;
	re(i,1,n){
		re(j,1,m){
			if(c[i][j]=='*'&&!del[i][j]){
//				cout<<i<<' '<<j<<endl;
				can=0;
			}
		}
	}
	if(!can) return puts("-1"),0;
	else{
		cout<<tot<<endl;
		re(i,1,tot){
			write(ans[i].x),prs(),write(ans[i].y),prs(),write(ans[i].r),prn();
		}
	}
    return 0;
}
/*
3 3
.*.
***
.*.
*/

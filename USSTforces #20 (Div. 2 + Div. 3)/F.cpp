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
const int maxn=2000005;
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

int n,a[maxn],b[maxn],mp[maxn];
bool is[maxn];
vei p;
vei fac[maxn];

void get(){
	re(i,2,2000000){
		if(!is[i]) p.pub(i);
		for(int j=0;j<p.size()&&i*p[j]<=2000000;++j){
			is[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	re(i,2,200002){
		int t=i;
		fo(j,0,p.size()){
			if(p[j]>200002) break;
			if(t%p[j]==0){
				fac[i].pub(p[j]);
				while(t%p[j]==0)
					t/=p[j];
			}
			if(t==0||t==1) break;
		}
	}
}

void gao(){
	get();
//	for(auto i:p) cout<<i<<endl;
//	re(i,2,100) {cout<<i<<":";for(auto j:fac[i]) cout<<j<<' ';cout<<endl;}
	b[1]=a[1];
	for(auto i:fac[a[1]]) mp[i]=1;
	int i=2;
	for(;i<=n;++i){
		bool can=1;
		for(auto j:fac[a[i]]){
			if(mp[j]){
				can=0;
				break;
			}
		}
		if(can){
			for(auto j:fac[a[i]]) mp[j]=1;
			b[i]=a[i];
		}
		else{
			int now=a[i]+1;
			while(1){
				bool all=1;
				for(auto j:fac[now]){
					if(mp[j]){
						all=0;
						break;
					}
				}
				if(all) break;
				now++;
			}
			for(auto j:fac[now]) mp[j]=1;
			b[i]=now;
			break;
		}
	}
	i++;
	int j=0;
	while(i<=n&&j<p.size()){
		while(mp[p[j]]) j++;
		b[i]=p[j];
		mp[p[j]]=1;
		i++;
	}
	re(i,1,n) cout<<b[i]<<' ';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;re(i,1,n) cin>>a[i];
	gao();
    return 0;
}
/*
3
3 18 2
*/

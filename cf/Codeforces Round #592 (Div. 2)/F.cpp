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
const int maxn=500005;
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

int n,k;
string s;
int l(int x){
	if(x==1) return n;
	else return x-1;
}
int r(int x){
	if(x==n) return 1;
	else return x+1;
}
bool is[maxn];
int dis(int x,int y){//
	if(x<=y) return y-x-1;
	else return n-y+x-1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>s;
    s='#'+s;
    int cnt=0;
    re(i,1,n){
		if(s[i]==s[l(i)]||s[i]==s[r(i)]){
			++cnt;
			is[i]=1;
		}
	}
	if(cnt==0){
		if(k%2==1){
			re(i,1,n) s[i]='W'+'B'-s[i];
		}
		re(i,1,n) cout<<s[i];
		return 0;
	}
	vector<bool> L(n),R(n);
	int last=n;
	while(!is[last]) last=l(last);
	rre(i,n,1){
		if(is[i]) last=i;
		else L[i]=last;
	}
	last=1;
	while(!is[last]) last=r(last);
	re(i,1,n){
		if(is[i]) last=i;
		else R[i]=last;
	}
	string t=s;
	re(i,1,n){
		if(is[i]) continue;
		int ld=dis(L[i],i),rd=dis(i,R[i]);//
		cout<<i<<' '<<ld<<' '<<rd<<endl;
		if(ld>k&&rd>k){
			if(k%2==1) t[i]='W'+'B'-s[i];
		}
		else if(s[L[i]]==s[R[i]]) t[i]=s[L[i]];
		else{
			if(ld<rd) t[i]=s[L[i]];
			else t[i]=s[R[i]];
		}
	}
	re(i,1,n) cout<<t[i];
    return 0;
}
/*
6 1
BWBBWW
*/

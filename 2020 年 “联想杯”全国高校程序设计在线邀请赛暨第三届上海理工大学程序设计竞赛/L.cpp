#include <bits/stdc++.h>
#define int long long
#define sci(a) scanf("%lld",&a)
#define scii(a,b) scanf("%lld%lld",&a,&b)
#define sciii(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define pri(a) printf("%lld",a)
#define prc(a) printf("%c",a)
#define prs() printf(" ")
#define prn() printf("\n")
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define each(i,a) for(auto i=a.begin();i!=a.end();++i)
#define body(a) a.begin(),a.end()
#define mkp make_pair
#define fst first
#define snd second
#define frt front
#define bak back
#define pub(a) push_back(a)
#define pob pop_back
#define puf(a) push_front(a)
#define pof pop_front
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define nmsl cout<<"NMSL"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'
#define lbd lower_bound
using namespace std;
typedef double db;
typedef pair<int,int> pii;
typedef pair<db,int> pdi;
typedef vector<int> vei;
typedef vector<pii> vep;
typedef vector<char> vec;
typedef vector<string> ves;
typedef map<int,int> mpii;
typedef map<pii,int> mppi;
typedef map<char,int> mpci;
typedef map<string,int> mpsi;
typedef deque<int> dqi;
typedef deque<pii> dqp;
typedef deque<char> dqc;
typedef deque<string> dqs;
typedef priority_queue<int> mxpi;
typedef priority_queue<int,vei,greater<int>> mnpi;
typedef priority_queue<pii> mxpp;
typedef priority_queue<pii,vep,greater<pii>> mnpp;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const db eps=1e-10;
const db pi=3.1415926535;
int lowb(int x){return x&-x;}
int mmax(int a,int b,int c){return max(max(a,b),c);}
int mmin(int a,int b,int c){return min(min(a,b),c);}
int count2(int x){return __builtin_popcountll(x);}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){if(x==0) return 1;return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
bool bigeql(db a,db b){if(a>b||fabs(a-b)<=eps)return true;return false;}
bool eql(db a,db b){if(fabs(a-b)<eps) return 1;return 0;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
int gcd(int x,int y){return __gcd(x,y);}
int lcm(int x,int y){return x*y/__gcd(x,y);}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}
int qpow(int a,int b,int mod){int tmp=a%mod,ans=1;while(b){if(b&1) ans=(ans*tmp)%mod;tmp=(tmp*tmp)%mod;b>>=1;}return ans;}
inline int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

int t,flg,F;
int cnt[10],sav[10];
int out[maxn],tmp[maxn];

void gao() {
	re(i,0,9) sav[i]=cnt[i];
	int j=0;
	while(j<=9) {
		while(sav[j]) {
			tmp[flg++]=j;
			sav[j]--;
		}
		++j;
	}
	bool bg=0;
	rre(i,flg-1,0) {
		if(tmp[i]<out[i]) break;
		else if(tmp[i]>out[i]) {
			bg=1;
			break;
		}
	}
	if(bg) fo(i,0,F) out[i]=tmp[i];
}

signed main() {
	FAST
    t=read();
    while(t--) {
		int ans=0,sum=0;
		re(i,0,9) cnt[i]=read(),sum+=cnt[i];
		re(i,0,sum+1) out[i]=tmp[i]=-1;
		bool ok1=0,ok2=0;
		if(cnt[0]) {
			ans=0;
			ok1=1;
		}
		if(cnt[4]) {
			ans=4;
			ok1=1;
		}
		if(cnt[8]) {
			ans=8;
			ok1=1;
		}
		//0 4 8
		int now=0;
		re(i,1,9) now|=(cnt[i]>0);
		if(cnt[0]&&!now) {
			puts("0");
			continue;
		}
		//all0
		F=sum;
		re(a,0,9) {
			re(b,0,9) {
				if((a*10+b)%4==0&&cnt[a]>0&&cnt[b]>0) {
					if(a==b&&a==0) {
						if(cnt[a]<2) continue;
					}
					//00
					if(a==b&&a==4) {
						if(cnt[a]<2) continue;
					}
					//44
					if(a==b&&a==8) {
						if(cnt[a]<2) continue;
					}
					//88
					flg=0;
					cnt[a]--;
					cnt[b]--;
					tmp[flg++]=b;
					tmp[flg++]=a;
					gao();
					cnt[a]++;
					cnt[b]++;
					ok2=1;
				}
			}
		}
		if(!ok1&&!ok2) puts("-1");
		else {
			if(ok2) {
				rre(i,F-1,0) write(out[i]);
				puts("");
			}
			else if(ok1) write(ans),puts("");
		}
	}
    return 0;
}
/*
1
100 1 0 0 0 0 0 0 0 0

7
0 1 1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
1 0 0 2 0 0 0 0 0 0
2 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1
9 0 0 0 0 0 0 0 0 0
*/

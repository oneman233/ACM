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
#define rre(i,a,b) for(register i=a;i>=b;--i)
#define all(i,a) for(auto i=a.begin();i!=a.end();++i)
#define mkp make_pair
#define fst first
#define snd second
#define frt front
#define bak back
#define pub(a) push_back(a)
#define pob() pop_back
#define puf(a) push_front(a)
#define pof() pop_front
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define nmsl cout<<"NMSL"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
typedef double db;
typedef pair<int,int> pii;
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

int n;
int x[maxn],y[maxn];
int l(int xi,int yi,int xj,int yj){return abs(xi-xj)+abs(yi-yj);}
int c[maxn],k[maxn];

int mp[2005][2005];
int dis[maxn],fa[maxn];

int prim(){
	int sum=0;
	int cnt=0;
	int s=0;
	re(i,1,n) dis[i]=mp[s][i],fa[i]=s;
	cnt++;
	while(1){
		int mn=inf;
		int now=-1;
		re(i,1,n){
			if(dis[i]!=0&&dis[i]<mn){
				mn=dis[i];
				now=i;
			}
		}
		if(now==-1) break;
		sum+=dis[now];
		dis[now]=0;
		cnt++;
		re(i,1,n){
			if(dis[i]!=0&&mp[now][i]<dis[i]){
				dis[i]=mp[now][i];
				fa[i]=now;
			}
		}
	}
	if(cnt<n) return -1;
	else return sum;
}

signed main(){
	FAST
	cin>>n;
	re(i,1,n) cin>>x[i]>>y[i];
	re(i,1,n) cin>>c[i];
	re(i,1,n) cin>>k[i];
	memmx(mp);
	re(i,1,n){
		re(j,1,n){
			if(i==j){
				mp[i][j]=0;
				continue;
			}
			mp[i][j]=l(x[i],y[i],x[j],y[j])*(k[i]+k[j]);
		}
	}
	re(i,1,n) mp[0][i]=c[i];
	int ans=prim();
	cout<<ans<<endl;
	vei v;
	re(i,1,n) if(fa[i]==0) v.pub(i);
	cout<<v.size()<<endl;
	fo(i,0,v.size()) cout<<v[i]<<' ';
	cout<<endl;
	vep vv;
	re(i,1,n){
		if(fa[i]!=0)
			vv.pub(mkp(i,fa[i]));
	}
	cout<<vv.size()<<endl;
	for(auto i:vv)
		cout<<i.fst<<' '<<i.snd<<endl;
	return 0;
}

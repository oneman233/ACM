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
typedef long double db;
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

int n,m,k;
int a[maxn],b[maxn],c[maxn];
vei e[maxn];
int now[maxn],suf[maxn];
bool is[maxn];
vep v,v2;

void gao()
{
//	re(i,1,n) cout<<now[i]<<' ';
	suf[n+1]=inf;
	rre(i,n,1) suf[i]=min(suf[i+1],now[i]);
	int ans=0;
	re(i,1,n-1)
	{
		for(auto j:e[i])
			v.pub(mkp(c[j],j));
		v.pub(mkp(c[i],i));
	}
	sort(v.begin(),v.end(),greater<pii>());
	now[n]-=suf[1];
	now[n]+=b[n];
	for(auto i:e[n])
	{
		v2.pub(mkp(c[i],i));
	}
	v2.pub(mkp(c[n],n));
	sort(v2.begin(),v2.end(),greater<pii>());
	fo(i,0,min((int)v2.size(),now[n]))
		ans+=v2[i].fst,is[v2[i].snd]=1;
	fo(i,0,v.size())
	{
		if(suf[1]==0) break;
		if(is[v[i].snd]) continue;
		ans+=v[i].fst;
		is[v[i].snd]=1;
		suf[1]--;
	}
	cout<<ans;
}

signed main()
{
    FAST
    cin>>n>>m>>k;
    re(i,1,n) cin>>a[i]>>b[i]>>c[i];
    re(i,1,m)
    {
		int x,y;
		cin>>x>>y;
		e[x].pub(y);
	}
	bool can=1;
	re(i,1,n)
	{
		if(k<a[i])
		{
			can=0;
			break;
		}
		k+=b[i];
		if(i!=n) now[i]=k-a[i+1];
		else now[i]=k;
	}
	if(!can) return cout<<-1,0;
	gao();
    return 0;
}

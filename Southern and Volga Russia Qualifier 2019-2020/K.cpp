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

int n;
struct node
{
	int a,b,c,d;
	node(){}
	node(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};
vector<node> ans;

int a[55][55];

bool ok(int x,int y)
{
	if(x==1||y==1||x==n||y==n) return 1;
	int cnt=0;
	cnt+=a[x-1][y];
	cnt+=a[x][y+1];
	cnt+=a[x][y-1];
	cnt+=a[x+1][y];
	return cnt!=0;
}

int gao(node x)
{
	if(x.a==1)
	{
		if(!ok(x.b,x.c))
		{
			cout<<"! "<<x.b<<' '<<x.c<<endl;
		}
		a[x.b][x.c]=x.d;
	}
	else
	{
		if(a[x.b][x.c]==0) a[x.b][x.c]=x.d;
		if(a[x.b][x.c+1]==0) a[x.b][x.c+1]=x.d;
		if(a[x.b+1][x.c]==0) a[x.b+1][x.c]=x.d;
		if(a[x.b+1][x.c+1]==0) a[x.b+1][x.c+1]=x.d;
	}
}

signed main()
{
    FAST
    cin>>n;
    int L=1,R=n,U=1,D=n;
    while(R-L+1>2)
    {
		re(i,L,R) if((i+U)%2==0) ans.pub(node(1,U,i,1)),gao(node(1,U,i,1));
		re(i,L,R) if((i+D)%2==0) ans.pub(node(1,D,i,1)),gao(node(1,D,i,1));
		re(i,U+1,D-1) if((i+L)%2==0) ans.pub(node(1,i,L,1)),gao(node(1,i,L,1));
		re(i,U+1,D-1) if((i+R)%2==0) ans.pub(node(1,i,R,1)),gao(node(1,i,R,1));
		ans.pub(node(2,U,R-1,2));
		ans.pub(node(2,D-1,L,2));
		gao(node(2,U,R-1,2));
		gao(node(2,D-1,L,2));
		for(int i=R-2;i>=L;i-=2)
		{
			ans.pub(node(1,U+1,i,1));
			ans.pub(node(2,U,i-1,2));
			gao(node(1,U+1,i,1));
			gao(node(2,U,i-1,2));
		}
		for(int i=L+2;i<=R-1;i+=2)
		{
			ans.pub(node(1,D-1,i,1));
			ans.pub(node(2,D-1,i,2));
			gao(node(1,D-1,i,1));
			gao(node(2,D-1,i,2));
		}
		for(int i=D-3;i>=U+2;i-=2)
		{
			ans.pub(node(1,i+1,L+1,1));
			ans.pub(node(2,i,L,2));
			gao(node(1,i+1,L+1,1));
			gao(node(2,i,L,2));
		}
		for(int i=U+2;i<=D-3;i+=2)
		{
			ans.pub(node(1,i,R-1,1));
			ans.pub(node(2,i,R-1,2));
			gao(node(1,i,R-1,1));
			gao(node(2,i,R-1,2));
		}
		L+=2;
		R-=2;
		U+=2;
		D-=2;
	}
	if(R-L+1==2)
	{
		ans.pub(node(1,L,U,1));
		ans.pub(node(1,R,D,1));
		ans.pub(node(2,L,U,2));
		gao(node(1,L,U,1));
		gao(node(1,R,D,1));
		gao(node(2,L,U,2));
	}
//	re(i,1,n) re(j,1,n) cout<<a[i][j]<<" \n"[j==n];
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i.a<<' '<<i.b<<' '<<i.c<<' '<<i.d<<endl;
    return 0;
}

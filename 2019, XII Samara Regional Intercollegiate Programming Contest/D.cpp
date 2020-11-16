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
#define endl '\n'
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

int n,q;
vei e[maxn];
int dep[maxn],fa[maxn][30];
int r[maxn],b[maxn];

void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;(1<<i)<=dep[x];++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto y:e[x])
	{
		if(y==f) continue;
		dfs(y,x);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	if(dep[x]!=dep[y])
	{
		int dif=dep[x]-dep[y];
		fo(i,0,lg(dif))
			if(dif&(1<<i))
				x=fa[x][i];
	}
	if(x==y) return x;
	rre(i,lg(dep[x])-1,0)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

signed main()
{
    FAST
    cin>>n;
    re(i,1,n-1)
    {
		int x,y;
		cin>>x>>y;
		e[x].pub(y);
		e[y].pub(x);
	}
	dfs(1,1);
	cin>>q;
	while(q--)
	{
		int R,B;
		cin>>R>>B;
		re(i,1,R) cin>>r[i];
		re(i,1,B) cin>>b[i];
		int tr=r[1],tb=b[1];
		re(i,2,R) tr=lca(tr,r[i]);
		re(i,2,B) tb=lca(tb,b[i]);
		bool can1=1,can2=1;
		re(i,1,R)
		{
			if(lca(r[i],tb)==tb)
			{
//				cout<<"! "<<r[i]<<' '<<tb<<endl;
				can1=0;
				break;
			}
		}
		re(i,1,B)
		{
			if(lca(b[i],tr)==tr)
			{
//				cout<<"! "<<b[i]<<' '<<tr<<endl;
				can2=0;
				break;
			}
		}
		if(can1||can2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7
6
2 2 4 5 6 7
2 2 4 6 5 7
2 1 4 5 2
2 1 4 5 1
1 1 1 2
6 1 1 2 3 4 5 6 7
*/

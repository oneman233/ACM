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
const int maxn=1000005;
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

int t,n,m,lst=0;
int a[25005][30],b[25005][30];
struct edge
{
	int to,a,b;
	edge(){}
	edge(int to,int a,int b):to(to),a(a),b(b){}
};
vector<edge> e[maxn],e2[maxn];
int disa[maxn],disb[maxn];
bool vis[maxn];

int get(int i,int j)
{
	return (i-1)*m+j;
}

void add(int x,int y,int a,int b)
{
	e[x].pub(edge(y,a,b));
}

void dij1()
{
	re(i,1,lst) disa[i]=inf,vis[i]=0;
	mnpp q;
	disa[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int now=q.top().snd;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		fo(i,0,e[now].size())
		{
			int to=e[now][i].to;
			int a=e[now][i].a;
			if(disa[now]+a<disa[to])
			{
				disa[to]=disa[now]+a;
				q.push({disa[to],to});
			}
		}
	}
	write(disa[lst]),prs();
	re(now,1,lst)
	{
		fo(j,0,e[now].size())
		{
			int to=e[now][j].to;
			int a=e[now][j].a;
			if(disa[to]==disa[now]+a)
				e2[now].pub(e[now][j]);
		}
	}
}

void dij2()
{
	re(i,1,lst) disb[i]=inf,vis[i]=0;
	mnpp q;
	disb[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int now=q.top().snd;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		fo(i,0,e2[now].size())
		{
			int to=e2[now][i].to;
			int b=e2[now][i].b;
			if(disb[now]+b<disb[to])
			{
				disb[to]=disb[now]+b;
				q.push({disb[to],to});
			}
		}
	}
	write(disb[lst]),prn();
}

signed main()
{
//    FAST
    t=read();
    while(t--)
    {
		n=read();m=read();
		re(i,1,n) re(j,1,m) a[i][j]=read();
		re(i,1,n) re(j,1,m-1) b[i][j]=read();
		lst=n*m+1;
		re(i,1,lst) e[i].clear(),e2[i].clear();
		re(i,1,n)
		{
			re(j,1,m)
			{
				if(i==n) add(get(i,j),lst,a[i][j],0);
				else add(get(i,j),get(i+1,j),a[i][j],0);
				if(j!=m) 
					add(get(i,j),get(i,j+1),0,b[i][j]),
					add(get(i,j+1),get(i,j),0,b[i][j]);
			}
		}
		dij1();
		dij2();
	}
    return 0;
}

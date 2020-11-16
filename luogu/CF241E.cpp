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

int n,m,x[maxn],y[maxn];
vei e[1005];
vep e2[1005];
int vis[1005];

bool dfs(int x)
{
	if(x==n) return 1;
	if(vis[x]!=0)
	{
		if(vis[x]==1) return 1;
		else if(vis[x]==2) return 0;
	}
	int ret=0;
	for(auto i:e[x])
		ret|=dfs(i);
	if(ret==0) vis[x]=2;
	else if(ret==1) vis[x]=1;
	return ret;
}

int cnt[1005];
bool inq[1005];
int dis[1005];

bool spfa()
{
	for(int i=1;i<=n;++i) dis[i]=inf;
	dis[1]=0;
	cnt[1]=1;
	inq[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int f=q.front();q.pop();
		inq[f]=0;
		for(auto i:e2[f])
		{
			if(dis[i.fst]>dis[f]+i.snd)
			{
				dis[i.fst]=dis[f]+i.snd;
				if(!inq[i.fst])
				{
					q.push(i.fst);
					cnt[i.fst]++;
					if(cnt[i.fst]>n) return 1;
					inq[i.fst]=1;
				}
			}
		}
	}
	return 0;
}

signed main()
{
    FAST
    cin>>n>>m;
    re(i,1,m)
    {
		cin>>x[i]>>y[i];
		e[x[i]].pub(y[i]);
	}
	vis[n]=1;
	dfs(1);
	for(int i=1;i<=n;++i) if(!vis[i]) vis[i]=2;
	for(int i=1;i<=m;++i)
	{
		if(vis[x[i]]==1&&vis[y[i]]==1)
		{
			e2[x[i]].push_back({y[i],2});
			e2[y[i]].push_back({x[i],-1});
		}
	}
	if(spfa()) return No,0;
    Yes;
    for(int i=1;i<=m;++i)
    {
		if(vis[x[i]]==1&&vis[y[i]]==1)
		{
			cout<<(dis[y[i]]-dis[x[i]])<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	return 0;
}
/*
4 4
1 2
2 4
1 3
1 4

6 5
1 3
2 3
3 4
3 5
5 6
*/

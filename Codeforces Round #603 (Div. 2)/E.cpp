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

int n;
char str[maxn];
int tag[maxn*4],mx[maxn*4],mn[maxn*4];

void down(int p)
{
	if(tag[p]!=0)
	{
		tag[ll(p)]+=tag[p];
		tag[rr(p)]+=tag[p];
		mx[ll(p)]+=tag[p];
		mx[rr(p)]+=tag[p];
		mn[ll(p)]+=tag[p];
		mn[rr(p)]+=tag[p];
		tag[p]=0;
	}
}

void up(int p)
{
	mx[p]=max(mx[ll(p)],mx[rr(p)]);
	mn[p]=min(mn[ll(p)],mn[rr(p)]);
}

void modi(int p,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		tag[p]+=v;
		mx[p]+=v;
		mn[p]+=v;
		return;
	}
	int m=mm(l,r);
	down(p);
	if(L<=m) modi(ll(p),l,m,L,R,v);
	if(R>m) modi(rr(p),m+1,r,L,R,v);
	up(p);
}

signed main()
{
    FAST
    int now=1,l=0,r=0;
    cin>>n;
    re(i,1,n)
    {
		char ch;
		cin>>ch;
		if(ch=='L') now=max(1ll,now-1);
		else if(ch=='R') now++;
		else if(ch=='(')
		{
			if(str[now]==')')
			{
				modi(1,1,1e6,now,1e6,2);
				++l;
				--r;
			}
			else if(str[now]!='(')
			{
				modi(1,1,1e6,now,1e6,1);
				++l;
			}
			str[now]=ch;
		}
		else if(ch==')')
		{
			if(str[now]=='(')
			{
				modi(1,1,1e6,now,1e6,-2);
				--l;
				++r;
			}
			else if(str[now]!=')')
			{
				modi(1,1,1e6,now,1e6,-1);
				++r;
			}
			str[now]=ch;
		}
		else
		{
			if(str[now]=='(')
			{
				modi(1,1,1e6,now,1e6,-1);
				--l;
			}
			else if(str[now]==')')
			{
				modi(1,1,1e6,now,1e6,1);
				--r;
			}
			str[now]=ch;
		}
		if(l!=r||mn[1]<0) cout<<-1<<' ';
		else cout<<mx[1]<<' ';
	}
    return 0;
}
/*
32
)))aaa(R(RaR))R(R(a)))RRaLaa)LRa
*/

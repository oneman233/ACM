#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}
inline int read()
{
    char ch=getchar();int s=0,w=1;
    while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}
    while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
    return s*w;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}

int head[maxn],to[maxn],e[maxn];//Graph
int sz[maxn],fa[maxn],dep[maxn],son[maxn];//using for d1
int ord[maxn],last[maxn];//using for d2
int tg,td,tt;//three timers,using for label graph,dfs and segment tree
struct segment_tree{
	int l,r,v,tag,ls,rs;
}tr[maxn];//segment tree

void add(int x,int y){
	e[++tg]=y;
	to[tg]=head[x];
	head[x]=tg;
}

void d1(int x){
	sz[x]=1;
	for(int i=head[x];i;i=to[i]){
		int y=e[i];
		if(y==fa[x]) continue;
		fa[y]=x;
		dep[y]=dep[x]+1;
		d1(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])
			son[x]=y;
	}
}

void d2(int x){
	ord[x]=++td;
	if(son[x]) d2(son[x]);
	for(int i=head[x];i;i=to[i]){
		int y=e[i];
		if(y!=fa[x]&&y!=son[x])
			d2(y);
	}
	last[x]=td;
}

void down(int p){
	if(tr[p].tag!=0){
		if(dep[tr[p].tag]>dep[tr[tr[p].ls].v]){
			tr[tr[p].ls].v=tr[p].tag;
			tr[tr[p].ls].tag=tr[p].tag;
		}
		if(dep[tr[p].tag]>dep[tr[tr[p].rs].v]){
			tr[tr[p].rs].v=tr[p].tag;
			tr[tr[p].rs].tag=tr[p].tag;
		}
		tr[p].tag=0;
	}
}

void build(int x,int y){
	++tt;
	tr[tt].l=x;
	tr[tt].r=y;
	tr[tt].v=1;
	tr[tt].tag=0;
	if(x==y){
		tr[tt].ls=tr[tt].rs=0;
		return;
	}
	else{
		int tmp=tt,m=mm(x,y);
		tr[tmp].ls=tt+1,build(x,m);
		tr[tmp].rs=tt+1,build(m+1,y);
	}
}

void modify(int p,int x,int y,int z){
	if(x<=tr[p].l&&tr[p].r<=y){
		if(dep[z]>dep[tr[p].v]){
			tr[p].v=z;
			tr[p].tag=z;
		}
		return;
	}
	down(p);
	int m=mm(tr[p].l,tr[p].r);
	if(x<=m) modify(tr[p].ls,x,y,z);
	if(y>m) modify(tr[p].rs,x,y,z);
}

int ask(int p,int pos){
	if(tr[p].l==tr[p].r) return tr[p].v;
	int m=mm(tr[p].l,tr[p].r);
	down(p);
	if(pos<=m) return ask(tr[p].ls,pos);
	else return ask(tr[p].rs,pos);
}

void modify1(int p,int x,int y){
	modify(1,ord[x],last[x],y);
}

int ask1(int p,int x){
	return ask(1,ord[x]);
}

int n,m,x,y,q;
char c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,n-1){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	d1(1);
	d2(1);
	build(1,n);
	re(i,1,m){
		cin>>c>>q;
		if(c=='C') modify1(1,q,q);
		else if(c=='Q') cout<<ask1(1,q)<<endl;
	}
    return 0;
}

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

int n,m,x[maxn],y[maxn];
vei g[maxn],scc[maxn];
int c[maxn];
int dfn[maxn],low[maxn],timer=0,cnt=0;
bool ins[maxn];
stack<int> s;
int ind[maxn],outd[maxn],sz[maxn];

void tarjan(int x){
	dfn[x]=low[x]=++timer;
	s.push(x);ins[x]=1;
	fo(i,0,g[x].size()){
		int y=g[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			c[y]=cnt,scc[cnt].pub(y);
		}while(x!=y);
	}
}

int f[maxn];
int _find(int x){
	if(f[x]!=x) f[x]=_find(f[x]);
	return f[x];
}
void _merge(int x,int y){
	x=_find(x),y=_find(y);
	f[x]=y;
}

void build(){
	re(i,1,cnt) f[i]=i;
	re(i,1,m){
		if(c[x[i]]!=c[y[i]])
			_merge(c[x[i]],c[y[i]]),
			outd[c[x[i]]]++,ind[c[y[i]]]++;
	}
	int ff=f[1];
	re(i,1,cnt) if(_find(i)!=ff){cout<<0;return;}
	int ans=0;
	int tmp=0;
	re(i,1,cnt){
		if(outd[i]==0) ans+=scc[i].size(),tmp++;
	}
	if(tmp>1) ans=0;
	cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,m){
		cin>>x[i]>>y[i];
		g[x[i]].pub(y[i]);
	}
	re(i,1,n) if(!dfn[i]) tarjan(i);
	build();
    return 0;
}
/*
3 2
1 2
2 3

3 2
1 2
1 3
*/

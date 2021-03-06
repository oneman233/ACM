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
typedef vector<int> veci;
typedef vector<pii> vecp;
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
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

int n,a[maxn],x,y;
veci tr[maxn];
int dp[maxn][30],dep[maxn],v[maxn];

void dfs1(int x,int f){
	dep[x]=dep[f]+1;
	dp[x][0]=f;
	fo(i,1,lg(dep[x]))
		dp[x][i]=dp[dp[x][i-1]][i-1];
	fo(i,0,tr[x].size())
		if(tr[x][i]!=f) dfs1(tr[x][i],x);
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int dif=dep[x]-dep[y];
	fo(i,0,lg(dif))
		if(dif&(1<<i)) x=dp[x][i];
		if(x==y) return x;
		else{
			rre(i,lg(dep[x])-1,0){
				if(dp[x][i]!=dp[y][i])
				x=dp[x][i],y=dp[y][i];
			}
			return dp[x][0];
		}
}

void dfs2(int x){
	fo(i,0,tr[x].size()){
		if(tr[x][i]!=dp[x][0])
			dfs2(tr[x][i]),
			v[x]+=v[tr[x][i]];
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    re(i,1,n) cin>>a[i];
    re(i,1,n-1) cin>>x>>y,tr[x].pub(y),tr[y].pub(x);
    dfs1(1,0);
    re(i,1,n-1){
    	int l=lca(a[i],a[i+1]);
    	v[a[i]]++;
    	v[a[i+1]]++;
    	v[l]--;
    	v[dp[l][0]]--;
	}
	dfs2(1);
	re(i,1,n){
		if(i!=a[1]) v[i]--;
		cout<<v[i]<<endl;
	}	
    return 0;
}

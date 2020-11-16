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

int n,m,x[maxn],y[maxn];
int val[maxn],dis[maxn];
vei g[maxn],rg[maxn];
int head[maxn],tot=0,e[maxn],to[maxn];
int dep[maxn],low[maxn],timer=0;
stack<int> s;
bool vis[maxn];
int idx[maxn],now=0;
int dp[maxn],ind[maxn];
int ans[maxn],ans_idx=0;

void add(int x,int y){
	e[++tot]=y;
	to[tot]=head[x];
	head[x]=tot;
}

void tarjan(int u){
	dep[u]=low[u]=++timer;
	s.push(u);
	vis[u]=1;
	for(int i=head[u];i;i=to[i]){
		int v=e[i];
		if(dep[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else{
			if(vis[v]) low[u]=min(low[u],dep[v]);
		}
	}
	if(low[u]==dep[u]){
		++now;
		while(s.top()!=u){
			idx[s.top()]=now;
			dis[now]+=val[s.top()];
			vis[s.top()]=0;
			s.pop();
		}
		idx[s.top()]=now;
		dis[now]+=val[s.top()];
		vis[s.top()]=0;
		s.pop();
		}
}

void topo(){
	queue<int> q;
	re(i,1,now){
		if(ind[i]==0) q.push(i); 
	}
	while(!q.empty()){
		int u=q.frt;
		q.pop();
		ans[++ans_idx]=u;
		fo(i,0,g[u].size()){
			int v=g[u][i];
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,n) cin>>val[i];
    re(i,1,m) cin>>x[i]>>y[i],add(x[i],y[i]);
    re(i,1,n) if(dep[i]==0) tarjan(i);
    re(i,1,m){
		if(idx[x[i]]!=idx[y[i]]){
			g[idx[x[i]]].pub(idx[y[i]]);
			rg[idx[y[i]]].pub(idx[x[i]]);
			ind[idx[y[i]]]++;
		}
	}
	topo();
	re(i,1,ans_idx){
		int k=ans[i];
		dp[k]=dis[k];
		fo(j,0,rg[k].size())
			dp[k]=max(dp[k],dp[rg[k][j]]+dis[k]);
	}
	int out=-inf;
	re(i,1,now) out=max(out,dp[i]);
	cout<<out;
	return 0;
}

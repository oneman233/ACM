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

int n,x[305],y[305],k=0;
vei e[305],son[305];
int cnt[305][305],f[305];
vei ans;
int way[305];
bool flg=0;

void dfs1(int x,int fa){
	f[x]=fa;
	int now=0;
	son[x].pub(x);
	fo(i,0,e[x].size()){
		int u=e[x][i];
		if(u!=fa){
			now++;
			dfs1(u,x);
			fo(j,0,son[u].size())
				son[x].pub(son[u][j]);
		}
	}
	sort(son[x].begin(),son[x].end());
	if(now==0) k++;
}

void dfs2(int x,int to){
	if(flg) return;
	if(ans.empty()||ans.bak!=x)
		ans.pub(x);
	if(x==to)
		return;
	bool can=0;
	fo(i,0,e[x].size()){
		int u=e[x][i];
		if(u==f[x]) continue;
		int k=lower_bound(son[u].begin(),son[u].end(),to)-son[u].begin();
		if(k>=son[u].size()) continue;
		if(son[u][k]==to){
			cnt[x][u]++;
			if(cnt[x][u]+cnt[u][x]>2){
				flg=1;
				return;
			}
			can=1;
			dfs2(u,to);
			break;
		}
	}
	if(!can){
		cnt[x][f[x]]++;
		if(cnt[x][f[x]]+cnt[f[x]][x]>2){
			flg=1;
			return;
		}
		dfs2(f[x],to);
	}
}

bool ok(){
	re(i,1,n-1){
		if(cnt[x[i]][y[i]]+cnt[y[i]][x[i]]!=2)
			return 0;
	}
	return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    re(i,1,n-1){
		cin>>x[i]>>y[i];
		e[x[i]].pub(y[i]);
		e[y[i]].pub(x[i]);
	}
	dfs1(1,1);
	re(i,1,k) cin>>way[i];
	dfs2(1,way[1]);
	re(i,1,k-1)
		dfs2(way[i],way[i+1]);
    dfs2(way[k],1);
	if(ok()&&!flg)
		fo(i,0,ans.size()) cout<<ans[i]<<' ';
	else cout<<-1;
	return 0;
}

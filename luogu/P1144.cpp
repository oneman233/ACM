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
typedef vector<int> vec;
typedef map<int,int> mpii;
typedef deque<int> deq;
typedef priority_queue<int> mxpq;
typedef priority_queue<int,vector<int>,greater<int> > mnpq;
typedef priority_queue<pii> mxpqii;
typedef priority_queue<pii,vector<pii>,greater<pii> > mnpqii;
const int maxn=2000005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=100003;
const db eps=1e-10;
int qpow(int a,int b){int tmp=a,ans=1;while(b){if(b&1){ans*=tmp,ans%=MOD;}tmp*=tmp,tmp%=MOD,b>>=1;}return ans;}
int lowbit(int x){return x&-x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int mmax(int a,int b,int c){return max(a,max(b,c));}
int mmin(int a,int b,int c){return min(a,min(b,c));}
void mod(int &a){a+=MOD;a%=MOD;}
bool chk(int cost){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

int n,m,x,y;
int head[maxn],to[maxn],e[maxn],tot=0;
int dis[maxn],ans[maxn];
bool vis[maxn];

void add(int x,int y){
	e[++tot]=y;
	to[tot]=head[x];
	head[x]=tot;
}

void bfs(){
	mem0(ans);
	mem0(vis);
	memmx(dis);
	dis[1]=0;
	ans[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int f=q.frt;
		q.pop();
		if(vis[f]) continue;
		vis[f]=1;
		for(int i=head[f];i;i=to[i]){
			int v=e[i];
			if(dis[f]+1<=dis[v]){
				if(dis[f]+1==dis[v]) ans[v]+=ans[f],mod(ans[v]);
				else ans[v]=ans[f],dis[v]=dis[f]+1;
				q.push(v);
			}
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,m){
    	cin>>x>>y;
    	add(x,y);
    	add(y,x);
	}
	bfs();
	re(i,1,n) cout<<ans[i]<<endl;
    return 0;
}

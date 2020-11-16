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
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=1e+7;
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

int n,p,x,y;
int w[maxn],sz[maxn],dp[maxn];
vec tr[maxn];

void dfs1(int x,int fa){
	w[x]++;
	fo(i,0,tr[x].size()){
		int son=tr[x][i];
		if(son!=fa){
			dfs1(son,x);
			w[x]+=w[son];
			sz[x]++;
		}
	}
}

void dfs2(int x,int fa){
	if(sz[x]==1){
		dp[x]=w[x]-1;
		return;
	}
	fo(i,0,tr[x].size()){
		int son=tr[x][i];
		if(son!=fa)
			dfs2(son,x);
	}
	vector<pii> wv,dpv;
	fo(i,0,tr[x].size()){
		int son=tr[x][i];
		if(son!=fa){
			wv.pub(mkp(w[son],son));
			dpv.pub(mkp(dp[son],son));
		}
	}
	int mx=0;
	fo(i,0,wv.size()){
		fo(j,0,dpv.size()){
			if(wv[i].snd!=dpv[j].snd)
				mx=max(mx,wv[i].fst+dpv[j].fst);
		}
	}
	dp[x]=mx;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p;
    if(n==1){
    	cout<<0;
    	return 0;
	}
    re(i,1,p){
    	cin>>x>>y;
    	tr[x].pub(y);
    	tr[y].pub(x);
	}
	dfs1(1,1);
	mem0(dp);
	dfs2(1,1);
	re(i,1,n) cout<<dp[i]<<' ';
	//cout<<n-dp[1];
    return 0;
}
/*
10 9
1 2
1 5
1 8
2 3
3 4
5 6
6 7
8 9
8 10
*/

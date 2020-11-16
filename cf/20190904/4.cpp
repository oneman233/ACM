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
const int maxn=1000005;
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
 
int n,m,timer=0,cut=0;
bool can=0;
char rhy[maxn];
vector<char> s[maxn];
vei dfn[maxn],low[maxn];
int a[4]={1,0,-1,0};
int b[4]={0,1,0,-1};

bool ok(int i,int j){
	if(i<0||i>=n||j<0||j>=m) return 0;
	if(s[i][j]=='#') return 0;
	return 1;
}

bool dfs(int i,int j){
	if(i<0||i>=n||j<0||j>=m) return 0;
	if(s[i][j]=='#') return 0;
	if(s[i][j]=='0') return 1;
	if(i==n-1&&j==m-1){
		can=1;
		s[i][j]='0';
		return 1;
	}
	bool now=0;
	now|=dfs(i+1,j);
	now|=dfs(i,j+1);
	if(now){
//		cout<<i<<' '<<j<<endl;
		s[i][j]='0';
		if(ok(i+1,j))
			s[i+1][j]='0';
		if(ok(i,j+1))
			s[i][j+1]='0';
		return 1;
	}
	else
		{s[i][j]='#';return 0;}
}
 
void tarjan(int x,int y){
	dfn[x][y]=low[x][y]=++timer;
	fo(i,0,4){
		int dx=x+a[i],dy=y+b[i];
		if(dx<0||dx>=n||dy<0||dy>=m||s[dx][dy]!='0')
			continue;
		if(!dfn[dx][dy]){
			tarjan(dx,dy);
			low[x][y]=min(low[x][y],low[dx][dy]);
			if(low[dx][dy]>=dfn[x][y]
			&&(x!=0||y!=0)){
//				cout<<x<<' '<<y<<endl;
				cut++;
			}
		}
		else{
			low[x][y]=min(low[x][y],dfn[dx][dy]);
		}
	}
}
 
signed main(){
    scc(n,m);
    fo(i,0,n){
		scanf("%s",rhy);
		fo(j,0,m)
			dfn[i].pub(0),low[i].pub(0),s[i].pub(rhy[j]);
	}
    dfs(0,0);
    s[0][0]=s[n-1][m-1]='0';
//    fo(i,0,n) fo(j,0,m) cout<<s[i][j]<<(j==m-1?'\n':' ');
    if(!can) cout<<0;
    else{
		tarjan(0,0);
		if(!cut) cout<<2;
		else cout<<1;
	}
    return 0;
}
/*
2 4
....
..#.

3 3
.#.
#..
...

4 4
....
....
.#..
.#..
*/

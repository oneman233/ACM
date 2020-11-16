#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define scs(a) scanf("%s",a) 
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
bool bigeql(db a,db b){if(a>b||fabs(a-b)<=eps)return true;return false;}
bool eql(db a,db b){if(fabs(a-b)<eps) return 1;return 0;}
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
int gcd(int a, int b){
	if(a==0) return b;
	if(b==0) return a;
	if(!(a&1)&&!(b&1)) return gcd(a>>1,b>>1)<<1;
	else if(!(b&1)) return gcd(a,b>>1);
	else if(!(a&1)) return gcd(a>>1,b);
	else return gcd(abs(a-b),min(a,b));
}
int lcm(int x,int y){return x*y/gcd(x,y);}

int n,m,mp[55][55];
int sx,sy,ex,ey;
char d;
int ans=inf;
int dis[55][55][1000];
bool v[55][55][1000];
queue<pair<pii,char> > q;
typedef pair<pii,char> pic;

char l(char c){
	if(c=='N') return 'W';
	if(c=='W') return 'S';
	if(c=='S') return 'E';
	if(c=='E') return 'N';
}

char r(char c){
	if(c=='N') return 'E';
	if(c=='E') return 'S';
	if(c=='S') return 'W';
	if(c=='W') return 'N';
}

bool ok(int i,int j,char c){
	int k=(int)c;
	if(1<=i&&i<=n&&1<=j&&j<=m&&
	mp[i][j]!=1&&mp[i+1][j]!=1&&mp[i][j+1]!=1&&mp[i+1][j+1]!=1)
		return 1;
	return 0;
}

void bfs(){
	memmx(dis);
	dis[sx][sy][d]=0;
	q.push(mkp(mkp(sx,sy),d));
	while(!q.empty()){
		pic f=q.front();
		q.pop();
		int x=f.fst.fst;
		int y=f.fst.snd;
		char dd=f.snd;
		int d=(int)dd;
//		cout<<x<<' '<<y<<' '<<d<<endl;
		if(v[x][y][d]) continue;
		v[x][y][d]=1;
		if(d=='N'){
			if(ok(x-3,y,d)&&ok(x-2,y,d)&&ok(x-1,y,d))
			q.push(mkp(mkp(x-3,y),d)),dis[x-3][y][d]=min(dis[x-3][y][d],dis[x][y][d]+1);
			if(ok(x-2,y,d)&&ok(x-1,y,d))
			q.push(mkp(mkp(x-2,y),d)),dis[x-2][y][d]=min(dis[x-2][y][d],dis[x][y][d]+1);
			if(ok(x-1,y,d))
			q.push(mkp(mkp(x-1,y),d)),dis[x-1][y][d]=min(dis[x-1][y][d],dis[x][y][d]+1);
		}
		else if(d=='E'){
			if(ok(x,y+3,d)&&ok(x,y+2,d)&&ok(x,y+1,d))
			q.push(mkp(mkp(x,y+3),d)),dis[x][y+3][d]=min(dis[x][y+3][d],dis[x][y][d]+1);
			if(ok(x,y+2,d)&&ok(x,y+1,d))
			q.push(mkp(mkp(x,y+2),d)),dis[x][y+2][d]=min(dis[x][y+2][d],dis[x][y][d]+1);
			if(ok(x,y+1,d))
			q.push(mkp(mkp(x,y+1),d)),dis[x][y+1][d]=min(dis[x][y+1][d],dis[x][y][d]+1);
		}
		else if(d=='S'){
			if(ok(x+3,y,d)&&ok(x+2,y,d)&&ok(x+1,y,d))
			q.push(mkp(mkp(x+3,y),d)),dis[x+3][y][d]=min(dis[x+3][y][d],dis[x][y][d]+1);
			if(ok(x+2,y,d)&&ok(x+1,y,d))
			q.push(mkp(mkp(x+2,y),d)),dis[x+2][y][d]=min(dis[x+2][y][d],dis[x][y][d]+1);
			if(ok(x+1,y,d))
			q.push(mkp(mkp(x+1,y),d)),dis[x+1][y][d]=min(dis[x+1][y][d],dis[x][y][d]+1);
		}
		else if(d=='W'){
			if(ok(x,y-3,d)&&ok(x,y-2,d)&&ok(x,y-1,d))
			q.push(mkp(mkp(x,y-3),d)),dis[x][y-3][d]=min(dis[x][y-3][d],dis[x][y][d]+1);
			if(ok(x,y-2,d)&&ok(x,y-1,d))
			q.push(mkp(mkp(x,y-2),d)),dis[x][y-2][d]=min(dis[x][y-2][d],dis[x][y][d]+1);
			if(ok(x,y-1,d))
			q.push(mkp(mkp(x,y-1),d)),dis[x][y-1][d]=min(dis[x][y-1][d],dis[x][y][d]+1);
		}
		if(ok(x,y,l(d)))
			q.push(mkp(mkp(x,y),l(d))),dis[x][y][l(d)]=min(dis[x][y][l(d)],dis[x][y][d]+1);
		if(ok(x,y,r(d)))
			q.push(mkp(mkp(x,y),r(d))),dis[x][y][r(d)]=min(dis[x][y][r(d)],dis[x][y][d]+1);
	}
	ans=min(ans,dis[ex][ey]['E']);
	ans=min(ans,dis[ex][ey]['S']);
	ans=min(ans,dis[ex][ey]['W']);
	ans=min(ans,dis[ex][ey]['N']);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    mem0(mp);
    re(i,1,n) re(j,1,m) cin>>mp[i][j];
    cin>>sx>>sy>>ex>>ey>>d;
	bfs();
	if(ans==inf) cout<<-1;
	else cout<<ans;
    return 0;
}
/*
20 20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 1 1 1 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 0 1 1 0 0 1 1 1 0 1 1 1
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
19 4 15 17 E
*/

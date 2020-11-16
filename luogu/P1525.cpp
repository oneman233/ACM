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
const int maxn=100005;
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
bool chk(int cost);
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

int n,m;
struct edge{
	int y,to;
}e[maxn];
int head[maxn],tot=0;
struct res{
	int x,y,v;
}r[maxn];
int color[maxn],vis[maxn];

bool cmp(res a,res b){
	return a.v<b.v;
}

void add(int x,int y){
	e[++tot].y=y;
	e[tot].to=head[x];
	head[x]=tot;
}

bool dfs(int x,int c){
	color[x]=c;
	for(int i=head[x];i;i=e[i].to){
		int y=e[i].y;
		if(color[y]==color[x]) return 0;
		if(color[y]==0&&!dfs(y,-c)) return 0;
	}
	return 1;
}

bool chk(int cost){
	if(cost>=r[m].v) return 1;
	mem0(e);
	mem0(head);
	mem0(color);
	mem0(vis);
	tot=0;
	rre(i,m,1){
		if(r[i].v<=cost) break;
		add(r[i].x,r[i].y);
		add(r[i].y,r[i].x);
		vis[r[i].x]=1;
		vis[r[i].y]=1;
	}
	re(i,1,n){
		if(vis[i]&&color[i]==0){
			if(!dfs(i,1)&&!dfs(i,-1)) return 0;
		}
	}
	return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
   	re(i,1,m) cin>>r[i].x>>r[i].y>>r[i].v;
   	sort(r+1,r+1+m,cmp);
   	cout<<half(0LL,1000000000LL);
    return 0;
}
/*
4 3
1 2 40
1 3 20
3 4 30
*/

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

int n,p[155];
db x[155],y[155];
char s[155];
char c[155][155];
db dis[155][155],mx[155],big[155];

void floyd(){
	re(k,1,n){
		re(i,1,n){
			re(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int _find(int x){
	if(x!=p[x])
		p[x]=_find(p[x]);
	return p[x];
}

void _merge(int x,int y){
	x=_find(x);
	y=_find(y);
	if(x!=y) p[x]=y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sc(n);
    re(i,1,n) p[i]=i;
    re(i,1,n) scanf("%lf%lf",&x[i],&y[i]);
    re(i,1,n){
		scanf("%s",s+1);
		re(j,1,n) c[i][j]=s[j];
	}
	re(i,1,n){
		re(j,1,n){
			if(i==j) dis[i][j]=0.0;
			else{
				if(c[i][j]=='1')
					dis[i][j]=len(x[i],y[i],x[j],y[j]),_merge(i,j);
				else dis[i][j]=inf;
			}
		}
	}
	db ans=inf;
	floyd();
	memmn(mx);
	memmn(big);
	re(i,1,n){
		re(j,1,n){
			if(_find(i)!=_find(j)||dis[i][j]==inf) continue;
			mx[i]=max(mx[i],dis[i][j]);
			big[_find(i)]=max(big[_find(i)],mx[i]);
		}
	}
	re(i,1,n){
		re(j,1,n){
			if(_find(i)==_find(j)) continue;
			db tmp=mx[i]+mx[j]+len(x[i],y[i],x[j],y[j]);
			ans=min(ans,max(tmp,max(big[_find(i)],big[_find(j)])));
		}
	}
	printf("%.6lf",ans);
	return 0;
}

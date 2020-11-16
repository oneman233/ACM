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

struct node{
	int a,b,c,cnt;
}o[maxn],t[maxn];
int n,c[maxn];

bool cmp(node a,node b){
	if(a.a!=b.a) return a.a>b.a;
	else return a.c<b.c;
}

int tr[maxn];
void add(int x,int y){
	for(;x<=n;x+=lowbit(x)) tr[x]+=y;
}
int sum(int x){
	int res=0;
	for(;x;x-=lowbit(x)) res+=tr[x];
	return res;
}

void cdq(int l,int r){
	if(l==r) return;
	int m=mm(l,r);
	cdq(l,m);
	cdq(m+1,r);
	int p=l,q=m+1,tot=l;
	while(p<=m&&q<=r){
		if(o[p].b>o[q].b) add(o[p].c,1),t[tot++]=o[p++];
		else o[q].cnt+=sum(n)-sum(o[q].c),t[tot++]=o[q++];
	}
	while(p<=m) add(o[p].c,1),t[tot++]=o[p++];
	while(q<=r) o[q].cnt+=sum(n)-sum(o[q].c),t[tot++]=o[q++];
	re(i,l,m) add(o[i].c,-1);
	re(i,l,r) o[i]=t[i];
}

signed main(){
    scanf("%lld",&n);
	int tmp;
	for(int i=1;i<=n;++i)
		scanf("%lld",&tmp),o[tmp].a=i;
	for(int i=1;i<=n;++i)
		scanf("%lld",&tmp),o[tmp].b=i;
	for(int i=1;i<=n;++i)
		scanf("%lld",&tmp),o[tmp].c=i;
	sort(o+1,o+1+n,cmp);
	cdq(1,n);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans+=o[i].cnt;
	printf("%lld",ans);
	return 0;
}


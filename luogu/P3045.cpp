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

int n,m,k;
struct aa{
	int p,c;
}a[maxn];
bool cmp(aa i,aa j){
	return i.c<j.c;
}
bool vis[maxn];
mnpq dif;
priority_queue<pii,vector<pii>,greater<pii> > c_k,p_k;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    re(i,1,n) cin>>a[i].p>>a[i].c;
    sort(a+1,a+1+n,cmp);
    int now=0,ans=0;
    re(i,1,k){
    	if(now+a[i].c>m){
    		cout<<ans;
    		return 0;
		}
		now+=a[i].c;
		ans++;
		dif.push(a[i].p-a[i].c);
	}
	re(i,k+1,n){
		c_k.push(mkp(a[i].c,i));
		p_k.push(mkp(a[i].p,i));
	}
	re(i,k+1,n){
		while(vis[p_k.top().snd]) p_k.pop();
		while(vis[c_k.top().snd]) c_k.pop();
		int p_p=p_k.top().snd;
		int p_c=c_k.top().snd;
		int a=c_k.top().fst;
		int b=dif.top();
		int c=p_k.top().fst;
		if(a+b<c){
			if(now+a+b>m)
				break;
			now+=a+b;
			dif.pop();
			c_k.pop();
			vis[p_c]=1;
		}
		else{
			if(now+c>m)
				break;
			now+=c;
			p_k.pop();
			vis[p_p]=1;
		}
		ans++;
	}
	cout<<ans;
    return 0;
}

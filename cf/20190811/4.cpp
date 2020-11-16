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
bool chk(int cost){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

const int MN = 2e3 + 5;
const int P = 1e3;
int n,k;
char ch[MN][MN];
int d[MN][MN];		
int s[MN][MN];	
int rs[MN],cs[MN];
int rk[MN][MN],ck[MN][MN];
int newr[MN][MN],newc[MN][MN];
int nrk[MN][MN],nck[MN][MN];
int ans;

signed main() {
	scc(n,k);
	re(i,1,n)
		scanf("%s",ch[i]+1);
	re(i,1,n)
		re(j,1,n)
			d[i][j]= ch[i][j]=='B',
			rs[i] += d[i][j],
			cs[j] += d[i][j],
			s[i][j] = d[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	re(i,1,n)
		re(j,k,n)
			rk[i][j] = s[i][j] - s[i][j-k] - s[i-1][j] + s[i-1][j-k],
			newr[i][j] = (rs[i] && rs[i]==rk[i][j]);
	re(i,k,n)
		re(j,1,n)
			ck[i][j] = s[i][j] - s[i-k][j] - s[i][j-1] + s[i-k][j-1],
			newc[i][j] = (cs[j] && cs[j]==ck[i][j]);
	re(i,1,n)
		re(j,1,n){
			nrk[i][j] = nrk[i-1][j] + newr[i][j];
			if(i>k)
				nrk[i][j] -= newr[i-k][j];
		}
	re(i,1,n)
		re(j,1,n){
			nck[i][j] = nck[i][j-1] + newc[i][j];
			if(j>k)
				nck[i][j] -= newc[i][j-k];
		}	 
	re(i,k,n)
		re(j,k,n)
			ans= max(ans, nrk[i][j]+nck[i][j]);
	re(t,1,n)
		ans+=rs[t]==0,
		ans+=cs[t]==0;
	cout<<ans;
	return 0;
}


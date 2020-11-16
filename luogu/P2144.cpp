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
typedef vector<int> veci;
typedef vector<pii> vecp;
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

int n,m,t[maxn];
string op[maxn];
veci vm,v1,v0;

#undef debug
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,n) cin>>op[i]>>t[i];
    int zero=0,one=(1<<lg(m))-1;
    #ifdef debug
    cout<<one<<endl;
    #endif
    re(i,1,n){
		if(op[i]=="AND") zero&=t[i],one&=t[i];
		else if(op[i]=="OR") zero|=t[i],one|=t[i];
		else if(op[i]=="XOR") zero^=t[i],one^=t[i];
	}
	#ifdef debug
	cout<<zero<<' '<<one<<endl;
	#endif
	fo(i,0,30){
		if(m&(1<<i)) vm.pub(1);
		else vm.pub(0);
		if(zero&(1<<i)) v0.pub(1);
		else v0.pub(0);
		if(one&(1<<i)) v1.pub(1);
		else v1.pub(0);
	}
	#ifdef debug
	fo(i,0,lg(m)) cout<<vm[i]<<' ';
	cout<<endl;
	fo(i,0,lg(m)) cout<<v0[i]<<' ';
	cout<<endl;
	fo(i,0,lg(m)) cout<<v1[i]<<' ';
	cout<<endl;
	#endif
	int ans=0;
	fo(i,0,30){
		if(v0[i]==0&&v1[i]==0){
			if(vm[i]==1){
				rre(j,i-1,0){
					if(vm[j]==0&&v0[j]==0&&v1[j]==1){
						ans+=(1<<j);
						vm[j]=1;
					}
				}
			}
			vm[i]=0;
		}
		else if(v0[i]==1&&v1[i]==0){
			ans+=(1<<i);
			if(vm[i]==1){
				rre(j,i-1,0){
					if(vm[j]==0&&v0[j]==0&&v1[j]==1){
						ans+=(1<<j);
						vm[j]=1;
					}
				}
			}
			vm[i]=0;
		}
		else if(v0[i]==0&&v1[i]==1){
			if(vm[i]==1) ans+=(1<<i);
		}
		else{
			ans+=(1<<i);
			if(vm[i]==1){
				rre(j,i-1,0){
					if(vm[j]==0&&v0[j]==0&&v1[j]==1){
						ans+=(1<<j);
						vm[j]=1;
					}
				}
			}
			vm[i]=0;
		}
	}
	cout<<ans;
    return 0;
}

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

int n,m;
int a[maxn],b,dp[45][45][45][45];
mpii mp;

int cal(int a,int b,int c,int d){
	return 1+a+b*2+c*3+d*4;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    re(i,1,n)
    	cin>>a[i];
    re(i,1,m)
    	cin>>b,
    	mp[b]++;
    dp[0][0][0][0]=a[1];
    re(i,0,mp[1]){
    	re(j,0,mp[2]){
    		re(p,0,mp[3]){
    			re(q,0,mp[4]){
    				if(i+j+p+q==0)
    					continue;
    				if(i-1>=0)
    					dp[i][j][p][q]=max(dp[i][j][p][q],dp[i-1][j][p][q]+a[cal(i,j,p,q)]);
					if(j-1>=0)
						dp[i][j][p][q]=max(dp[i][j][p][q],dp[i][j-1][p][q]+a[cal(i,j,p,q)]);
					if(p-1>=0)
						dp[i][j][p][q]=max(dp[i][j][p][q],dp[i][j][p-1][q]+a[cal(i,j,p,q)]);
					if(q-1>=0)
						dp[i][j][p][q]=max(dp[i][j][p][q],dp[i][j][p][q-1]+a[cal(i,j,p,q)]);
				}
			}
		}
	}
	cout<<dp[mp[1]][mp[2]][mp[3]][mp[4]];
    return 0;
}

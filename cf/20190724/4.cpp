#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define re(i,a,b) for(int i=a;i<=b;++i)
#define prn() printf("\n")
#define prs() printf(" ")
#define mkp make_pair
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst frist
#define snd second
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define debug
using namespace std;
typedef vector<int> vec;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=1e+7;
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
int lg(int x){return (int)log2(x)+1;}

int q,n,k;
int ans;
int a[maxn],b[maxn],c[maxn];
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>q;
    while(q--)
	{
		ans=inf;
		cin>>n>>k;
		cin>>s;
		fo(i,0,n)
		{
			if(s[i]=='R')
			{
				if(i%3==0)
				{
					a[i+1]=a[i];
					b[i+1]=b[i]+1;
					c[i+1]=c[i]+1;
				}
				else if(i%3==1)
				{
					a[i+1]=a[i]+1;
					b[i+1]=b[i];
					c[i+1]=c[i]+1;
				}
				if(i%3==2)
				{
					b[i+1]=b[i]+1;
					a[i+1]=a[i]+1;
					c[i+1]=c[i];
				}
			}
			else if(s[i]=='G')
			{
				if(i%3==1)
				{
					a[i+1]=a[i];
					b[i+1]=b[i]+1;
					c[i+1]=c[i]+1;
				}
				else if(i%3==2)
				{
					a[i+1]=a[i]+1;
					b[i+1]=b[i];
					c[i+1]=c[i]+1;
				}
				if(i%3==0)
				{
					b[i+1]=b[i]+1;
					a[i+1]=a[i]+1;
					c[i+1]=c[i];
				}
			}
			else
			{
				if(i%3==2)
				{
					a[i+1]=a[i];
					b[i+1]=b[i]+1;
					c[i+1]=c[i]+1;
				}
				else if(i%3==0)
				{
					a[i+1]=a[i]+1;
					c[i+1]=c[i]+1;
					b[i+1]=b[i];
				}
				if(i%3==1)
				{
					b[i+1]=b[i]+1;
					a[i+1]=a[i]+1;
					c[i+1]=c[i];
				}
			}
		}
		for(int i=0;i<=(n-k);i++)
		{
			if(a[i+k]-a[i]<ans)
			{
				ans=a[i+k]-a[i];
			}
			if(b[i+k]-b[i]<ans)
			{
				ans=b[i+k]-b[i];
			}
			if(c[i+k]-c[i]<ans)
			{
				ans=c[i+k]-c[i];
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

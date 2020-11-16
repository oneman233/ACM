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
bool chk(int cost){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
bool isp(int x){if(x==1)return false;if(x==2)return true;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}
const int N=1000005;
char s[2][N],ans[N];
int ex[N],exnext[N],cur,n;
typedef unsigned long long ull;

void get_exnext(char s[N])
{
    int n=strlen(s),p=1,j,i;
    exnext[0]=n;
    for(i=0;i<n-1&&s[i]==s[i+1];i++);
    exnext[1]=i;
    for(i=2;i<n;i++)
        if(exnext[i-p]+i<p+exnext[p])
            exnext[i]=exnext[i-p];
        else
        {
            j=exnext[p]+p-i;
            if(j<0) j=0;
            while(i+j<n&&s[j]==s[i+j]) j++;
            exnext[i]=j;
            p=i;
        }
}

void exkmp(char s1[N],char s2[N])
{
    int l1=strlen(s1),l2=strlen(s2),p=0,i,j;
    get_exnext(s2);
    for(i=0;i<l1&&i<l2&&s1[i]==s2[i];i++);
    ex[0]=i;
    for(int i=1;i<l1;i++)
    {
        if(exnext[i-p]+i<p+ex[p])
            ex[i]=exnext[i-p];
        else
        {
            j=ex[p]+p-i;
            if(j<0) j=0;
            while(i+j<l1&&s1[i+j]==s2[j]) j++;
            ex[i]=j;
            p=i;
        }
    }
}

const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxm = 1e7;

string uu[maxn];
ull base=229;
const ull Mod1=998244353;
const ull Mod2=1e9+7;
ull hashs(string& s,int* u1,int* u2,int op=-1)
{
    int len=s.length();
    ull ans=0;
    if(op!=-1){
		for(int i=op;i<len;i++)
	    {
	    	u1[i+1] = (u1[i]*base+(ull)s[i])%Mod1;
	    	u2[i+1] = (u2[i]*base+(ull)s[i])%Mod2;
		}
		return ans;
	}
    u1[0] = u2[0] = 0;
    for(int i=0;i<len;i++)
    {
    	u1[i+1] = (u1[i]*base+(ull)s[i])%Mod1;
    	u2[i+1] = (u2[i]*base+(ull)s[i])%Mod2;
	}
    return ans;
}

ull k[maxn][2];
pair<ull,ull> get(int l,int r,int* u1,int* u2)
{
	l++;r++;
	ull a = (u1[r]-u1[l-1]*k[r-l+1][0]%Mod1+Mod1)%Mod1;
	ull b = (u2[r]-u2[l-1]*k[r-l+1][1]%Mod2+Mod2)%Mod2;
	return mkp(a,b);
}

int u1[maxn],u2[maxn],u3[maxn],u4[maxn];
signed main()
{
	k[0][0] = 1;k[0][1] = 1;
	for(int i=1;i<1e6+5;i++) k[i][0] = k[i-1][0]*base%Mod1;
	for(int i=1;i<1e6+5;i++) k[i][1] = k[i-1][1]*base%Mod2;
	
	int n;
	sc(n);
	for(int i=0;i<n;i++) cin>>uu[i];
	cout<<uu[0];
	string sh = uu[0];
	int sz = 0;
	for(int i=1;i<n;i++)
	{
		int le = sh.length();
		int len = min(le,uu[i].length());
		hashs(sh,u1,u2,sz);
		sz = le;
		hashs(uu[i],u3,u4);
		{
			int fg = 0;
			int pos = le-len;
			for(int j=pos;j<le;j++)
			{
				if(get(j,le-1,u1,u2)==get(0,le-j-1,u3,u4))
				{
					for(int op=le-j;op<uu[i].length();op++)
					{
						printf("%c",uu[i][op]);
						sh+=uu[i][op];
					}
					fg = 1;
					break;
				}
			}
			if(fg==0){
				cout<<uu[i];
				sh+=uu[i];
			}
		}
		
	}
	return 0;
}

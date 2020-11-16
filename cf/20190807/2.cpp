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

string s;
int to[10][10],x,y;

void dfs(int now,int step)
{
	if(to[now][(now+x)%10]==-1)
		to[now][(now+x)%10]=step,dfs((now+x)%10,step+1);
	if(to[now][(now+y)%10]==-1)
		to[now][(now+y)%10]=step,dfs((now+y)%10,step+1);
}

void floyd()
{
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				if(to[i][k]!=-1&&to[k][j]!=-1&&(to[i][j]==-1||to[i][j]>to[i][k]+to[k][j]))
					to[i][j]=to[i][k]+to[k][j];
}

signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.length();
	for(x=0;x<10;x++){
		for(y=0;y<10;y++)
		{
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
					to[i][j]=-1;
			for(int i=0;i<10;i++)
				to[(i+x)%10][i]=1,to[(i+y)%10][i]=1;
			floyd();
			int ans=0;
			for(int i=1;i<n;i++)
				if(to[s[i]-'0'][s[i-1]-'0']==-1)
				{
					ans=-1;
					break;
				}
				else
					ans+=to[s[i]-'0'][s[i-1]-'0']-1;
			cout<<ans;
			if(y!=9)
				cout<<' ';
		}
		if(x!=9)
			cout<<endl;
	}
	return 0;
}


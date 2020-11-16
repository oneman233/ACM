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

int n;
char sss[maxn*2];
char ss[155][75];
int c[15000][26],ed[15000],fl[15000];
int res[155],cnt;
queue<int> q;
inline void init(){
	mem0(c);
	mem0(ed);
	mem0(res);
	while(!q.empty()) q.pop();
	cnt=0;
}
inline void ins(char *s,int x){
	int l=strlen(s),now=0;
	for(int i=0;i<l;++i){
		if(!c[now][s[i]-'a']) c[now][s[i]-'a']=++cnt;
		now=c[now][s[i]-'a']; 
	}
	ed[now]=x;
}
inline void build(){
	for(int i=0;i<26;++i)
		if(c[0][i]) fl[c[0][i]]=0,q.push(c[0][i]);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			if(c[f][i]){
				fl[c[f][i]]=c[fl[f]][i];
				q.push(c[f][i]);
			}
			else c[f][i]=c[fl[f]][i];
		}
	}
}
inline void query(char *s){
	int l=strlen(s),now=0;
	for(int i=0;i<l;++i){
		now=c[now][s[i]-'a'];
		for(int t=now;t;t=fl[t]){
			if(ed[t])
				res[ed[t]]++;
		}
	}
	int mx=-inf;
	for(int i=1;i<=n;++i)
		mx=max(mx,res[i]);
	pr(mx),prn();
	re(i,1,n){
		if(res[i]==mx)
			printf("%s\n",ss[i]);
	}
}

signed main(){
    while(sc(n)){
    	if(n==0) break;
		init();
		re(i,1,n) scanf("%s",ss[i]),ins(ss[i],i);
		build();
		scanf("%s",sss);
		query(sss);
	}
    return 0;
}

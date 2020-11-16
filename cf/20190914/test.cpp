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
//bool chk(int now){}
//int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int mm(int l,int r){return (l+r)/2;}
int lg(int x){if(x==0) return 1;return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
//db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
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
 
int t,n,len;
char s[maxn];
vector<int> a,pos[15];
int c[maxn],b[maxn];
int _find(int k)
{
    int l=1,r=len,ans=1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(b[mid]>=k)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

bool chk(){
	vei one,two;
	re(i,1,n){
		if(c[i]==1) one.pub(a[i]);
		else two.pub(a[i]);
	}
	vei v,v2;
	fo(i,0,one.size()) v.pub(one[i]),v2.pub(one[i]);
	fo(i,0,two.size()) v.pub(two[i]),v2.pub(two[i]);
	sort(v2.begin(),v2.end());
	fo(i,0,n){
		if(v[i]!=v2[i]) return 0;
	}
	return 1;
}

void get()
{
    len=1;b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]<b[len]) b[++len]=a[i];
        else
        {
            int p=_find(a[i]);
            b[p]=a[i];
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
		cin>>n;
		cin>>s;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		a.clear();
		a.pub(100);
		mem0(c);
		fo(i,0,n) a.pub(s[i]-'0');
		get();
		if(len>=3){
			cout<<'-'<<endl;
			continue;
		}
		else if(len==1){
			re(i,1,n) cout<<1;
			cout<<endl;
			continue;
		}
		re(i,0,9) pos[i].clear();
		int mx=-inf;
		re(i,1,n) pos[a[i]].pub(i),mx=max(mx,a[i]);
		re(i,1,n){
			int p;
			bool is=0;
			bool fill=0;
			rre(j,a[i]-1,0){
				if(pos[j].size()==0) continue;
				int k=0;
				while(pos[j][k]<i&&k<pos[j].size()){
					if(c[pos[j][k]]==2){
						c[i]=2;
						fill=1;
						break;
					}
					k++;
				}
				if(fill) break;
				p=upper_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
				if(p!=pos[j].size()){
					c[i]=2;
					c[pos[j][p]]=1;
					is=1;
					break;
				}
			}
			if(fill) continue;
			if(!is) c[i]=1;
		}
		if(a[n]==mx) c[n]=2;
//		re(i,1,n) cout<<c[i];cout<<endl;
		if(!chk()) cout<<'-'<<endl;
		else{
		re(i,1,n) cout<<c[i];
		cout<<endl;}
	}
    return 0;
}
/*
100
5
46368
3
326
*/

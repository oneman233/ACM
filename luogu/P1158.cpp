#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}

int a1,b1,a2,b2,n,x,y,mx[maxn];
int l(int a,int b,int c,int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
vector<pii> v;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a1>>b1>>a2>>b2>>n;
    re(i,1,n)
    {
        cin>>x>>y;
        v.pub(mkp(l(a1,b1,x,y),l(a2,b2,x,y)));
    }
    sort(v.begin(),v.end());
    mx[n-1]=v[n-1].snd;
    rre(i,n-2,0)
        mx[i]=max(mx[i+1],v[i].snd);
    int ans=min(v[n-1].fst,mx[0]);
    re(i,0,n-2)
        ans=min(ans,v[i].fst+mx[i+1]);
    cout<<ans;
    return 0;
}

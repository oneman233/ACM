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
#define pii pair<int,int>
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst first
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

int n,len;
int a[maxn];
map<int,int> m;
vector<int> v;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>len;
    re(i,1,n)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    int he=0;
    for(auto i=m.begin();i!=m.end();++i){
        v.pub(i->snd);
        he+=i->snd;
    }
    int ans=inf,sum=0;
    int contain;
    if((8*len)/n<=60)
        contain=1LL<<((8*len)/n);
    else
        contain=inf;
    if(contain>=v.size()){
        cout<<0;
        return 0;
    }
    deque<int> wnd;
    for(int i=0;i<contain;++i){
        wnd.pub(v[i]);
        sum+=v[i];
    }
    ans=min(ans,he-sum);
    for(int i=contain;i<v.size();++i){
        wnd.pub(v[i]);
        sum+=v[i];
        sum-=wnd.front();
        wnd.pof();
        ans=min(ans,he-sum);
    }
    cout<<ans;
    return 0;
}
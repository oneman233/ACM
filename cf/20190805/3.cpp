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
bool chk(int cost);
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(!chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int lg(int x){return (int)log2(x)+1;}

int n,k;
int a[maxn];

bool chk(int cost)
{
    bool can=true;
    int flag=0;
    int cnt=0;
    rre(i,n,n/2+1)
    {
        if(cost>a[i])
            cnt+=cost-a[i];
        if(cnt>k){
            can=false;
            break;
        }
    }
    if(can)
        flag++;
    can=true;
    cnt=0;
    re(i,1,n/2+1)
    {
        if(cost>a[i])
            cnt+=cost-a[i];
        if(cnt>k){
            can=false;
            break;
        }
    }
    if(can)
        flag++;
    if(flag>0)
        return true;
    else
        return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    re(i,1,n)
        cin>>a[i];
    sort(a+1,a+1+n);
    int ans=half(1,10000000000);
    if(ans-1>=a[n/2+1])
        cout<<ans-1;
    else
        cout<<a[n/2+1];
    return 0;
}

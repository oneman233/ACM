#include <bits/stdc++.h>
#define re(i,a) for(int i=1;i<=a;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
#define debug(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll maxn=2000;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}


ll n,m;
ll a[maxn+5][maxn+5];
ll dp[maxn+5][maxn+5];

ll l(ll x)
{
    if(x!=1)
        return x-1;
    else
        return m;
}

ll r(ll x)
{
    if(x!=m)
        return x+1;
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(dp,0x3f,sizeof(dp));
    cin>>n>>m;
    re(i,m)
    {
        re(j,n)
        {
            cin>>a[i][j];
        }
    }
    re(i,m)
        dp[i][1]=a[i][1];
    for(int j=2;j<=n;++j)
    {
        for(int i=1;i<=m;++i)
        {
            dp[i][j]=min(dp[l(i)][j-1],dp[i][j-1])+a[i][j];
        }
    }
    ll ans=inf;
    re(i,m)
        ans=min(ans,dp[i][n]);
    cout<<ans;
    return 0;
}

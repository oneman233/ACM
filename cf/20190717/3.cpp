#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
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
#define int long long
using namespace std;
typedef long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n;
int h1[maxn],h2[maxn];
int dp[maxn][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    re(i,1,n)
        cin>>h1[i];
    re(i,1,n)
        cin>>h2[i];
    re(i,1,n)
    {
        dp[i][0]=h1[i];
        dp[i][1]=h2[i];
    }
    re(i,1,n)
    {
        dp[i][0]=mmax(dp[i][0],dp[i-1][0],dp[i-1][1]+h1[i]);
        dp[i][1]=mmax(dp[i][1],dp[i-1][1],dp[i-1][0]+h2[i]);
    }
    int ans=-inf;
    re(i,1,n)
        ans=mmax(ans,dp[i][0],dp[i][1]);
    cout<<ans;
    return 0;
}
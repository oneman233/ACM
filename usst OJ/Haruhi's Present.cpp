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
using namespace std;
const int MAX=1000;
const int inf=0x3f3f3f3f;
const double pi=3.1415926535;
const int mod=10007;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

ll a,b,k,n;
ll c[MAX+5][MAX+5];

ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    re(i,0,MAX)
        c[i][0]=c[i][i]=1;
    re(i,2,MAX)
        re(j,1,i-1)
            c[i][j]=(c[i-1][j]%mod+c[i-1][j-1]%mod)%mod;
    while(scanf("%lld %lld %lld %lld",&a,&b,&k,&n)!=EOF){
        ll ans=(c[k][n]%mod*qpow(a,n)%mod*qpow(b,k-n)%mod)%mod;
        prl(ans);
        prn();
    }
    return 0;
}

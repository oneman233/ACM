#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%llu",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
typedef unsigned long long ll;
const int maxn=2000000;
const ll mod=998244353;

ll n;
ll a[maxn+5],b[maxn+5];

int main()
{
    scl(n);
    for(ll i=0;i<n;++i)
    {
        scl(a[i]);
        a[i]*=(n-i)*(i+1);
    }
    for(ll i=0;i<n;++i)
        scl(b[i]);
    sort(a,a+n);
    sort(b,b+n);
    ll ans=0;
    fo(i,0,n)
    {
        ans+=a[i]%mod*b[n-i-1]%mod;
        ans%=mod;
    }
    prl(ans);
    return 0;
}
/*
i love long long
so i write a song
long long is long
but not too long
i love long long
life is short
but long long is long
i promise you
if next time i mod long long
i will jump into river long
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000000;

ll qpow(ll a,ll b)
{
    ll tmp=a,ans=1LL;
    while(b)
    {
        if(b&1)
        {
            ans*=tmp;
            ans%=mod;
        }
        tmp*=tmp;
        tmp%=mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    ll k,n;
    scanf("%lld %lld",&k,&n);
    ll ans=n*(qpow(n,k-1)-qpow(n-1,k-1)+mod)%mod;
    printf("%lld",ans%mod);
    return 0;
}

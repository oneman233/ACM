#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=10007;

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
    int c=1;
    ll a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        ll ans;

        printf("Case %d: %lld\n",c,ans%mod);
    }
    return 0;
}

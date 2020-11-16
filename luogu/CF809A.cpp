#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
using namespace std;
const int maxn=300005;
const int mod=1000000007;

int qpow(int a,int b)
{
    int tmp=a;
    int ans=1;
    while(b){
        if(b&1){
            ans*=tmp;
            ans%=mod;
        }
        tmp*=tmp;
        tmp%=mod;
        b>>=1;
    }
    return ans%mod;
}

int n,x[maxn];
int ans=0;

signed main()
{
    scl(n);
    for(int i=1;i<=n;++i)
        scl(x[i]);
    sort(x+1,x+1+n);
    for(int i=1;i<=n;++i){
        ans+=(x[i]%mod*qpow(2LL,i-1)%mod)%mod;
        ans%=mod;
        ans-=(x[i]%mod*qpow(2LL,n-i)%mod)%mod;
        ans+=mod;
        ans%=mod;
    }
    prl(ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll n;
struct matrix
{
    ll a11,a12,a21,a22;
    matrix(ll a,ll b,ll c,ll d)
    {
        a11=a;a12=b;a21=c;a22=d;
    }
};

matrix mul(matrix a,matrix b)
{
    ll a11=(a.a11*b.a11+a.a12*b.a21)%mod;
    ll a12=(a.a11*b.a12+a.a12*b.a22)%mod;
    ll a21=(a.a21*b.a11+a.a22*b.a21)%mod;
    ll a22=(a.a21*b.a12+a.a22*b.a22)%mod;
    matrix ans(a11,a12,a21,a22);
    return ans;
}

matrix qpow()
{
    matrix ans(1,0,0,1),tmp(0,1,1,1);
    ///求2n-1项，只算2n-2次方
    n=2*n-2;
    while(n)
    {
        if(n&1)
            ans=mul(ans,tmp);
        tmp=mul(tmp,tmp);
        n/=2;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        matrix m=qpow();
        ll a2n_1=(m.a11+2*m.a21)%mod;
        ll a2n=(m.a12+2*m.a22)%mod;
        printf("%lld %lld %lld\n",a2n_1,a2n,(a2n_1+a2n)%mod);
    }
    return 0;
}

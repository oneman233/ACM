#include <bits/stdc++.h>
#define ll long long
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

ll n,m,p;
const int maxn=100005;
ll fac[maxn];

void getfac(ll p)//算好到n位置的所有阶乘，对p取个余
{
    fac[0]=1;
    _rep(i,1,p)
    {
        fac[i]=fac[i-1]*i%p;
    }
}

ll qpow(ll a,ll b,ll p)
{
    ll ans=1;
    while(b)
    {
        if(b&1)//奇数则把答案算到贡献上去
            ans*=a%p;
        a*=a%p;
        b/=2;
    }
    return ans;
}

/*快速幂和阶乘都是需要每一步对p取余，乘法中取余不影响最后结果*/

ll lucas(ll a,ll b,ll p)
{
    ll ans=1;
    while(a&&b)//a，b均不为0时
    {
        ll tempa=a%p;
        ll tempb=b%p;
        if(a<b)
            return 0;
        ans=(ans*fac[a]*qpow(fac[b]*fac[a-b]%p,p-2,p))%p;
        /*
        C(a,b) =a! / ( b! * (a-b)! ) mod p
        其实就是求 ( a! / (a-b)!)  * ( b! )^(p-2) mod p
        费马小定理
        */
        a/=p;
        b/=p;
    }
    return ans;
}

int main()
/*将不超过m个豆子放在n棵不同的树上，一共有多少种方法。*/
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&p);
        getfac(p);
        printf("%lld\n",lucas(n+m,m,p));
    }
    return 0;
}

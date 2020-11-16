#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;
const ll mod=998244353;

int main()
{
    ll w,q;
    ll ans[Max+10];
    scanf("%lld %lld",&w,&q);
    ll cheng=3;
    _rep(i,1,Max+5)
    {
        ans[i]=w;
        w*=cheng;
        w%=mod;
        cheng+=2;
        cheng%=mod;
    }
    ll que;
    while(q--)
    {
        scanf("%lld",&que);
        printf("%lld\n",ans[que]);
    }
    return 0;
}

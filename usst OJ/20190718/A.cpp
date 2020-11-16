#include <bits/stdc++.h>
//#define debug
using namespace std;
typedef long long ll;

ll n,a,b,c;

ll lcm(ll x,ll y)
{
    return x*y/__gcd(x,y);
}

ll lcm(ll x,ll y,ll z)
{
    return lcm(lcm(x,y),z);
}

ll tmp[1000000];

int main()
{
    cin>>n>>a>>b>>c;
    ll ans=0;
    ans+=n/a+n/b+n/c-2*(n/lcm(a,b))-2*(n/lcm(a,c))-2*(n/lcm(b,c))+4*(n/lcm(a,b,c));
    #ifdef debug
    for(int i=a;i<=n;i+=a)
        tmp[i]=1-tmp[i];
    for(int i=b;i<=n;i+=b)
        tmp[i]=1-tmp[i];
    for(int i=c;i<=n;i+=c)
        tmp[i]=1-tmp[i];
    for(int i=1;i<=n;++i)
        if(tmp[i])
            ans++;
    #endif
    cout<<ans;
    return 0;
}

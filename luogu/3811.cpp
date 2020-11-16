#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inv[3000000];

int main()
{
    ll n,p;
    cin>>n>>p;
    inv[1]=1;
    printf("1\n");
    for(ll i=2;i<=n;++i)
    {
        inv[i]=(p/i)*inv[p%i];
        printf("%lld\n",inv[i]);
    }
    return 0;
}

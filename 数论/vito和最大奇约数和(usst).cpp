#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        if(i&1)
            ans+=i;
        else
        {
            ll temp=i;
            while(!(temp&1))
                temp>>=1;
            ans+=temp;
        }
    }
    cout<<ans;
    return 0;
}

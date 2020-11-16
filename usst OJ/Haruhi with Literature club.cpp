#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
ll a[200005];

bool chk(ll as)
{
    ll pre=1LL;
    for(int i=1;i<=k-1;++i){
        if(pre>=a[i])
            pre=a[i]+as/2+1;
        else{
            ll t=2*(a[i]-pre);
            if(t>as)
                return false;
            pre=a[i]+max(1LL,(as-t)/2+1);
        }
    }
    if(pre>=a[k]){
        if(a[k]+as/2<n)
            return false;
    }
    else{
        ll t=2*(a[k]-pre);
        if(t>as)
            return false;
        if(a[k]+(as-t)/2<n)
            return false;
    }
    return true;
}

ll half(ll l,ll r)
{
    while(l<=r){
        ll m=(l+r)/2;
        if(chk(m)) r=m-1;
        else l=m+1;
    }
    return l;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
        cin>>a[i];
    ll as=half(1LL,2LL*n);
    cout<<as;
    return 0;
}

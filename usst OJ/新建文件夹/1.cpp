#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll n;
ll a[2000005];
ll as[2000005];

ll m(ll a)
{
    return (a+mod)%mod;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    as[0]=m(a[0]);
    cout<<as[0]<<endl;
    for(int i=1;i<n;++i){
        as[i]=m(a[i]+as[i-1]+a[i]*as[i-1]);
        cout<<as[i]<<endl;
    }
    return 0;
}

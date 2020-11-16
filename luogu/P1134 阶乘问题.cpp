#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main()
{
    cin>>n;
    ll tmp=1;
    for(ll x=2;x<=n;++x){
        tmp*=x;
        while(tmp%10==0)
            tmp/=10;
        tmp%=1000000;
    }
    cout<<tmp%10;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> v;

int main()
{
    cin>>n;
    for(ll i=1;i*i<=n;++i)
        v.push_back(i*i);
    int pos=lower_bound(v.begin(),v.end(),n)-v.begin();
    if(v[pos]==n)
        cout<<1;
    else{
        ll tp=n-v[pos-1];
        tp%=9;
        if(tp!=0)
            cout<<tp+0;
        else
            cout<<9;
    }
    return 0;
}

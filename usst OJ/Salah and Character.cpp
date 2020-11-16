#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k,n;

int main()
{
    vector<ll> v;
    v.push_back(0LL);
    for(ll i=1;((i+1)*i/2)<(1LL<<31);++i)
        v.push_back((i+1)*i/2);
    cin>>k;
    while(k--){
        cin>>n;
        int pos=lower_bound(v.begin(),v.end(),n)-v.begin();
        ///cout<<pos<<" "<<v[pos]<<endl;
        ll num=n-v[pos-1];
        num%=26;
        if(num==0)
            cout<<'z'<<endl;
        else
            cout<<(char)(num-1+'a')<<endl;
    }
    return 0;
}

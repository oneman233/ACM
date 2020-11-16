#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=91948941;

ll t,n,a[55];

ll pow(ll n)
{
    ll ans=1,tmp=2;
    while(n){
        if(n&1){
            ans*=tmp;
            tmp%=mod;
        }
        tmp*=tmp;
        tmp%=mod;
        n>>=1;
    }
    return ans;
}

int main()
{
    a[1]=1;
    for(int i=2;i<=50;++i){
        ll sum=0;
        for(int j=1;j<i;++j){
            sum+=a[j];
            sum%=mod;
        }
        a[i]=(pow(i-1)+sum)%mod;
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}

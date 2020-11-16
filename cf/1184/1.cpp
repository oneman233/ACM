#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll r;
    cin>>r;
    for(ll x=1;x<=1000000;++x){
        if((r-1-x*x-x)%(2*x)==0&&(r-1-x*x-x)>0){
            cout<<x<<' '<<(r-1-x*x-x)/(2*x);
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

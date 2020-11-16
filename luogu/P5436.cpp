#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll n;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        ll tmp=n-1;
        while(1){
            if(__gcd(tmp,n)==1){
                cout<<tmp*n<<endl;
                break;
            }
        }
    }
    return 0;
}

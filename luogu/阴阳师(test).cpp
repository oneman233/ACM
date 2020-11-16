#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,n,ans=0;
    while(cin>>a>>b>>n){
        ans=0;
        for(long long i=a;i<=b;++i){
            if(__gcd(i,n)>1&&i!=n)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

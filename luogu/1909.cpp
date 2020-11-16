#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long long ans=10000000000;
    long long a1,a2,b1,b2,c1,c2;
    cin>>n;
    cin>>a1>>a2;
    cin>>b1>>b2;
    cin>>c1>>c2;
    if(n%a1==0)
        ans=min(ans,n/a1*a2);
    else
        ans=min(ans,(n/a1+1)*a2);
    if(n%b1==0)
        ans=min(ans,n/b1*b2);
    else
        ans=min(ans,(n/b1+1)*b2);
    if(n%c1==0)
        ans=min(ans,n/c1*c2);
    else
        ans=min(ans,(n/c1+1)*c2);
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=100000;

///异或有传递性，可以当成某种意义上的乘法，用差分去做
///0^x=x

int n,q;
int l,r;
ll a[Max+5],Xor[Max+5],x;

int main()
{
    cin>>n>>q;
    _for(i,1,n+1)
        cin>>a[i];
    while(q--)
    {
        cin>>l>>r>>x;
        Xor[l-1]^=x;
        Xor[r]^=x;
    }
    ll temp=Xor[0];
    for(int i=1;i<=n;++i)
    {
        cout<<(a[i]^temp)<<" ";
        temp^=Xor[i];
    }
    return 0;
}

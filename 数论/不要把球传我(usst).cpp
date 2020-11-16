#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A(ll m,ll n)
{
    if(m<n)
        return 0;
    else if(m==n)
        return 1;
    else
    {
        ll mu=1,zi=1;
        for(int i=m;i>=m-n+1;--i)
            mu*=i;
        for(int i=n;i>=1;--i)
            zi*=i;
        return mu/zi;
    }
}

int main()
{
    int n;
    while(cin>>n)
        cout<<A(n-1,3)<<endl;
    return 0;
}

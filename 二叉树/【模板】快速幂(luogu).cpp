#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b,p,k;

ll qpow(ll x,ll y,ll z)
{
    ll ans=1;
    ll tmp=x;
    while(y)
    {
        if(y&1)
        {
            ans*=tmp;
            ans%=z;
        }
        tmp*=tmp;
        tmp%=z;
        y/=2;
    }
    return ans;
}

int main()
{
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<qpow(b,p,k)%k;
    ///��ȡ��һ�η�ֹ0�η����������
    return 0;
}

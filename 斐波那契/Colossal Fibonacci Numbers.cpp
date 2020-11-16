#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int Max=1000000;

///尾数循环的性质
///个位数60一循环，后两位数300一循环
///a^b应该不断对circle取余

ll a,b,n;
ll remain[Max];
ll circle;///循环节
int t;

ll qpow(ll x,ll y)
{
    if(x==0)
        return 0;
    if(y==0)
        return 1;
    ll ans=1;
    ll temp=x;
    while(y)
    {
        if(y&1)
        {
            ans*=temp;
            ans%=circle;
        }
        temp*=temp;
        temp%=circle;
        y/=2;
    }
    return ans;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        memset(remain,0,sizeof(remain));
        remain[0]=0;remain[1]=1;///init
        for(int i=2;i<=n*n;++i)
        {
            remain[i]+=remain[i-1]+remain[i-2];
            remain[i]%=n;
            if(remain[i]==remain[1]&&remain[i-1]==remain[0])
            {
                circle=i-1;
                break;
            }
        }
        /*
        for(int i=0;i<=100;++i)
            cout<<remain[i]<<" ";
        */
        ll ab=qpow(a,b);
        ab%=circle;
        cout<<remain[ab]<<endl;
    }

    return 0;
}

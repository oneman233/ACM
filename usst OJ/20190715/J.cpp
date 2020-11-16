#include <bits/stdc++.h>
#define move rhyrhyrhy
using namespace std;
typedef long long ll;
ll mod=99037660;

ll n,f[5]={0,2,4,6,9};
ll one[5][5]={0,0,0,0,0,
              0,1,0,0,0,
              0,0,1,0,0,
              0,0,0,1,0,
              0,0,0,0,1};
ll move[5][5]={0,0,0,0,0,
              0,1,0,1,1,
              0,1,0,0,0,
              0,0,1,0,0,
              0,0,0,1,0};

struct mat
{
    ll m[5][5];
    mat(ll mm[5][5])
    {
        for(int i=1;i<=4;++i)
            for(int j=1;j<=4;++j)
                m[i][j]=mm[i][j];
    }
    void operator *= (mat& mm)
    {
        ll tmp[5][5];
        memset(tmp,0,sizeof(tmp));
        for(int i=1;i<=4;++i)
        {
            for(int j=1;j<=4;++j)
            {
                for(int k=1;k<=4;++k)
                {
                    tmp[i][j]+=m[i][k]*mm.m[k][j];
                    tmp[i][j]%=mod;
                }
            }
        }
        for(int i=1;i<=4;++i)
            for(int j=1;j<=4;++j)
                m[i][j]=tmp[i][j];
    }
};

ll qpow()
{
    mat a(one),b(move);
    n-=4;
    while(n)
    {
        if(n&1)
            a*=b;
        b*=b;
        n>>=1;
    }
    ll ans=0;
    for(int i=1;i<=4;++i)
    {
        ans+=a.m[1][i]*f[5-i];
        ans%=mod;
    }
    return ans;
}

int main()
{
    scanf("%lld",&n);
    if(n<=4)
        printf("%lld",f[n]);
    else
        printf("%lld",qpow());
    return 0;
}

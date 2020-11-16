#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000000;

ll s,sum[maxn+5];

int main()
{
    sum[1]=1LL;
    for(int i=2;i<=maxn;++i)
        sum[i]=sum[i-1]+i;
    scanf("%lld",&s);
    ll mn=1;
    for(ll i=2;sum[i]<=s;++i)
    {
        if((i&1)&&s%i==0)
            mn=i;
        if(i%2==0&&s%i==i/2)
            mn=i;
    }
    s-=(mn+1)*mn/2;
    ll add=s/mn;
    printf("%lld %lld",1+add,mn+add);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=99037660;
const ll maxn=1000001;

ll n,as[maxn],f[maxn];

void init()
{
    as[1]=2;
    as[2]=4;
    as[3]=6;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=(maxn+1)/2;++i){
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
        as[(i-1)*2]=f[i]*f[i];
        as[(i-1)*2]%=mod;
    }
    for(int i=5;i<=maxn;i+=2){
        as[i]=as[i-1]+as[i-2];
        as[i]%=mod;
    }
}

int main()
{
    init();
    cin>>n;
    cout<<as[n];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int n;
ll m,p;

ll pow(ll a)
{
    ll ans=1;
    while(a){
        if(a&1){
            ans*=m;
            ans%=p;
        }
        m*=m;
        m%=p;
        a>>=1;
    }
    return ans;
}

int gcd(int i,int j)
{
    if(i<j){
        int tmp=i;
        i=j;
        j=tmp;
    }
    if(j==0)
        return i;
    else
        return gcd(j,i%j);
}

int main()
{
    cin>>n>>m>>p;
    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                if(gcd(i,j)%k==0)
                    ans+=gcd(i,j);
            }
        }
    }
    cout<<pow(ans);
    return 0;
}
/*
100 2000000000 2000000000
*/

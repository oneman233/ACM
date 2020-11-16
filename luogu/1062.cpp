#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull k,n;
ull ans=0;

ull pow(int x)
{
    ull ans=1;
    while(x--)
        ans*=k;
    return ans;
}

int main()
{
    cin>>k>>n;
    for(int i=0;i<=10;++i)
    {
        if(n&(1<<i))
            ans+=pow(i);
    }
    cout<<ans;
    return 0;
}

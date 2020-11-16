#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    int k;
    long long ans=1000000000;
    cin>>a>>b;
    for(int i=0;i<=4500000;++i)
    {
        if((a+i)*(b+i)/__gcd(a+i,b+i)<ans)
        {
            ans=(a+i)*(b+i)/__gcd(a+i,b+i);
            k=i;
        }
    }
    cout<<k;
    return 0;
}

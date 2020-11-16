#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x,n;
    long long ans=0;
    cin>>x>>n;
    while(n)
    {
        if(x!=6&&x!=7)
            ans+=250;
        x++;
        if(x>=8)
            x=1;
        n--;
    }
    cout<<ans;
    return 0;
}

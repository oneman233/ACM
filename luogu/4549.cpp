#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin>>n;
    int ans=0,tmp;
    while(n--)
    {
        cin>>tmp;
        if(tmp<0)
            tmp*=-1;
        ans=__gcd(ans,tmp);
    }
    cout<<ans;
    return 0;
}

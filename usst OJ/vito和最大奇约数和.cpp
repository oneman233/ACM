#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a,ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        a=i;
        if(a%2==0)
        {
            while(a%2==0)
                a/=2;
        }
        ans+=a;
    }
    cout<<ans;
    return 0;
}

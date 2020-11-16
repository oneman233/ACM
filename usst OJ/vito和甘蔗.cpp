#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long long ans=0;
    long long temp=1;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    while(temp<=n)
        temp*=2;
    if(temp==n)
    {
        cout<<n-1;
        return 0;
    }
    else
    {
        temp/=2;
        while(n>=1)
        {
            if(n>=temp)
            {
                n-=temp;
                ans+=temp-1;
            }
            temp/=2;
        }
    }
    cout<<ans;
    return 0;
}

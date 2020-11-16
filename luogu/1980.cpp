#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x;
    long long ans=0;
    cin>>n>>x;
    while(n)
    {
        long long temp=n;
        while(temp)
        {
            if(temp%10==x)
                ans++;
            temp/=10;
        }
        n--;
    }
    cout<<ans;
    return 0;
}

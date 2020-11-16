#include <bits/stdc++.h>
using namespace std;

bool isprime(long long x)
{
    if(x==0 || x==1)
        return false;
    for(long long i=2;i*i<=x;++i)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n,k;
    int ans=0;
    long long nu[25];
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>nu[i];
    for(int i=0;i<(1<<n);++i)
    {
        int cnt=0;
        long long sum=0;
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j))
            {
                sum+=nu[j];
                ++cnt;
                if(cnt>k)
                    break;
            }
        }
        if(cnt==k && isprime(sum))
            ++ans;
    }
    cout<<ans;
    return 0;
}

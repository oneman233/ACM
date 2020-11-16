#include <bits/stdc++.h>
using namespace std;

bool isprime(long long a)
{
    if(a==2)
        return true;
    for(long long i=2;i<sqrt(a);i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n,k;
    int ans=0;
    long long a[25];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<(1<<n);i++)
    {
        long long sum=0;
        int geshu=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                geshu++;
                sum+=a[j];
            }
        }
        if(geshu==k)
        {
            if(isprime(sum))
                ans++;
        }
    }
    cout<<ans;
    return 0;
}

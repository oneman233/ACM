#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if(x==1||x==2)
        return true;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=n/2;i>=1;i--)
        {
            if(isprime(i)&&isprime(n-i))
            {
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
    }
    return 0;
}

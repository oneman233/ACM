#include <bits/stdc++.h>
using namespace std;

bool isprime(long long a)
{
    if(a<=1)
        return false;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    long long num;
    while(n--)
    {
        cin>>num;
        if(isprime(num))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

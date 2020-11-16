#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=2;i<=100000;++i)
        if(isprime(i))
            v.push_back(i);
    for(int i=0;i<v.size();++i)
    {
        if(n%v[i]==0&&isprime(n/v[i]))
        {
            cout<<n/v[i];
            break;
        }
    }
    return 0;
}

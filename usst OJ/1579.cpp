#include <bits/stdc++.h>
using namespace std;

bool isprime(int num)
{
    if(num<=1)
        return false;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=1;i<20000;i++)
    {
        if(isprime(i))
            s.insert(i);
    }
/*
    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<endl;
*/
    for(auto a=s.begin();a!=s.end();a++)
    {
        for(auto b=s.begin();b!=s.end();b++)
        {
            if(isprime(n-*a-*b))
            {
                cout<<*a<<" "<<*b<<" "<<n-*a-*b;
                return 0;
            }
        }
    }
    return 0;
}

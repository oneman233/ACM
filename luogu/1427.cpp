#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    stack<ll>s;
    while(cin>>n)
    {
        if(n==0)
            break;
        s.push(n);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

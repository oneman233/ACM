#include <bits/stdc++.h>
using namespace std;

bool huzhi(int a,int b)
{
    for(int i=2;i<=min(a,b);i++)
    {
        if(a%i==0&&b%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    unsigned long long ans;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<2;
        return 0;
    }
    if(n%2==1)
        ans=n*(n-1)*(n-2);
    else
    {
        if(n%3==0)
            ans=(n-1)*(n-2)*(n-3);
        else
            ans=n*(n-1)*(n-3);
    }
    cout<<ans;
    return 0;
}

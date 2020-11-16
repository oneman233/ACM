#include <bits/stdc++.h>
using namespace std;

long long jiecheng(int n)
{
    long long out=1;
    while(n)
    {
        out*=n;
        n--;
    }
    return out;
}

int main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=jiecheng(i);
    cout<<sum;
    return 0;
}

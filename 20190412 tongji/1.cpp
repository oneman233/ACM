#include <bits/stdc++.h>
using namespace std;

unsigned long long gcd(int a,int b)
{
    if(a<b)
    {
        unsigned long long tmp=a;
        a=b;
        b=tmp;
    }
    while(b!=0)
    {
        unsigned long long tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long n,a,b;
        unsigned long long ans=0;
        scanf("%llu %llu %llu",&n,&a,&b);
        ans+=n/a;
        ans+=n/b;
        ans-=n/(a*b/gcd(a,b));
        cout<<ans<<endl;
    }
    return 0;
}

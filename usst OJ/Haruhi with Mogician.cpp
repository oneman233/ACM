#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,as=0;
    cin>>n;
    for(int i=1;i<n;++i)
        if(__gcd(i,n)==1)
            as++;
    cout<<as<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long ans=1;
    cin>>n;
    for(int i=0;i<n;i++)
        ans*=2;
    cout<<"2^"<<n<<" = "<<ans;
    return 0;
}

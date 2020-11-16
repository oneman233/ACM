#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    cin>>n;
    double bu=2;
    int ans=1;
    double sum=0;
    while(true)
    {
        sum+=bu;
        bu*=0.98;
        if(sum>=n)
            break;
        ans++;
    }
    cout<<ans;
    return 0;
}

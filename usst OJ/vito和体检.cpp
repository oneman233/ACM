#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m;
    int ans=0;
    cin>>n>>k>>m;
    if(m>=n)
        ans=k;
    else
    {
        if((n*k)%m==0)
            ans=n*k/m;
        else
            ans=n*k/m+1;
    }
    cout<<ans;
    return 0;
}

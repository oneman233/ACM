#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long ans[155];
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    for(int i=4;i<=n;i++)
        ans[i]=ans[i-2]+ans[i-3];
    cout<<ans[n];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,nn[105];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>nn[i];
    int ans=-100;
    for(int i=1;i<=n-1;++i)
        ans=max(ans,nn[i+1]-nn[i]);
    cout<<ans;
    return 0;
}

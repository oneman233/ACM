#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[200010],ans=-1000000,sum=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        sum+=a[i];
        if(sum<0)
        {
            ans=max(ans,a[i]);
            sum=0;
        }
        else
            ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}

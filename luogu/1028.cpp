#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long ans[1005];
    for(int i=1;i<=n;i++)
        ans[i]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            ans[i]+=ans[j];
        }
    ans[i]++;//×Ô¼º
    }
    cout<<ans[n];
    return 0;
}

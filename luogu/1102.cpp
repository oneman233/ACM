#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,a[200010];
    map<int,long long> m;
    cin>>n>>c;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;++i)
        m[a[i]+c]++;
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=m[a[i]];
    }
    cout<<ans;
    return 0;
}

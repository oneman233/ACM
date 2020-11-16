#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int cnt=1;
    for(int i=1;i<=n-i+1;i++){
        if(cnt&1)
            swap(a[i],a[n-i+1]);
        cnt++;
    }
    for(int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,t,ans=0,flag=-100;
int a[200005];

int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i){
        if(flag<a[i])
            ans+=t;
        else
            ans+=a[i]+t-1-flag;
        flag=a[i]+t-1;
    }
    cout<<ans;
    return 0;
}

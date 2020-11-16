#include <bits/stdc++.h>
using namespace std;

int n,a[300005],b[300005];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    int ans=0;
    ///a[0] b[0] a[n-1] b[n-1]
    for(int i=n-1;i>=0;--i)
    {
        if(a[0]!=0&&b[i]!=0&&a[0]!=b[i])
            ans=max(ans,i+1);
        if(a[0]==0||b[i]==0)
            ans=max(ans,i+1);
    }
    for(int i=n-1;i>=0;--i)
    {
        if(b[0]!=0&&a[i]!=0&&b[0]!=a[i])
            ans=max(ans,i+1);
        if(b[0]==0||a[i]==0)
            ans=max(ans,i+1);
    }
    for(int i=0;i<n;++i)
    {
        if(a[n-1]!=0&&b[i]!=0&&a[n-1]!=b[i])
            ans=max(ans,n-i);
        if(a[n-1]==0||b[i]==0)
            ans=max(ans,n-i);
    }
    for(int i=0;i<n;++i)
    {
        if(b[n-1]!=0&&a[i]!=0&&b[n-1]!=a[i])
            ans=max(ans,n-i);
        if(b[n-1]==0||a[i]==0)
            ans=max(ans,n-i);
    }
    /*
    for(int i=n-1;i>=0;--i)
    {
        if(a[0]!=0&&a[i]!=0&&a[0]!=a[i])
            ans=max(ans,i);
        if(a[0]==0&&a[i]==0)
            ans=max(ans,i);
    }
    for(int i=n-1;i>=0;--i)
    {
        if(b[0]!=0&&b[i]!=0&&b[0]!=b[i])
            ans=max(ans,i);
        if(b[0]==0&&b[i]==0)
            ans=max(ans,i);
    }
    for(int i=0;i<n;++i)
    {
        if(a[n-1]!=0&&a[i]!=0&&a[n-1]!=a[i])
            ans=max(ans,n-1-i);
        if(a[n-1]==0&&a[i]==0)
            ans=max(ans,n-1-i);
    }
    for(int i=0;i<n;++i)
    {
        if(b[n-1]!=0&&b[i]!=0&&b[n-1]!=b[i])
            ans=max(ans,n-1-i);
        if(b[n-1]==0&&b[i]==0)
            ans=max(ans,n-1-i);
    }
    */
    cout<<ans;
    return 0;
}

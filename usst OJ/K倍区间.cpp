#include <bits/stdc++.h>

using namespace std;

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    int n,k;
    int r[100005];
    int sum[100005];
    int ans=0;
    cin>>n>>k;
    cin>>r[0];
    sum[0]=r[0];
    for(int i=1;i<n;i++)
    {
        cin>>r[i];
        sum[i]=sum[i]+r[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((sum[j]-sum[i])%k==0)
                ans++;
        }
    }
    cout<<ans;
}

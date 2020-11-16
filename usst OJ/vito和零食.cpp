#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num[1005];
    int ans[1005];
    int wei=1000000,idx;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(num[i]<wei)
            {
                wei=num[i];
                idx=i;
            }
        }
        ans[j]=idx;
        num[idx]=1000000;
        wei=1000000;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i];
        if(i!=(n-1))
            cout<<" ";
    }
    return 0;
}

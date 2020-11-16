#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num[100005];
    int small=10001;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n;i++)
    {
        if(num[i]<small)
            small=num[i];
    }
    for(int i=0;i<n;i++)
    {
        num[i]-=small;
    }
    ans+=small;
    small=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]==0);
        else
        {
            if(num[i+1]>=num[i]);
            else
            {
                ans+=num[i]-small;
                small=num[i+1];
            }
        }
    }
    cout<<ans;
    return 0;
}

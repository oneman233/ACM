#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int ans=0;
    int num[105];
    int cha[105];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=1;i<n;i++)
        cha[i]=num[i]-num[i-1];
    for(int i=1;i<n;i++)
    {
        if(cha[i]>ans)
            ans=cha[i];
    }
    cout<<ans;
    return 0;
}

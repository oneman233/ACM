#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long jian[300005],xue[300005];
    for(int i=0;i<n;i++)
    {
        cin>>jian[i];
        if(jian[i]>=n)
            jian[i]=n;
    }
    for(int i=0;i<n;i++)
        cin>>xue[i];
    int ans=0;
    int chafen[300005];
    for(int i=0;i<n;i++)
        chafen[i]=0;
    for(int i=1;i<n;i++)
    {
        if(i-jian[i]<0)
            chafen[0]++;
        else
            chafen[i-jian[i]]++;
        chafen[i]--;
    }
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=chafen[i];
        if(temp<=xue[i])
            ans++;
    }
    cout<<ans;
    return 0;
}

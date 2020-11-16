#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long wea[n];
    for(int i=0;i<n;i++)
        cin>>wea[i];
    int ans=0,temp=1;
    for(int i=1;i<n;i++)
    {
        if(wea[i]>wea[i-1])
            temp++;
        else
        {
            if(temp>ans)
                ans=temp;
            temp=1;
        }
    }
    cout<<ans;
    return 0;
}

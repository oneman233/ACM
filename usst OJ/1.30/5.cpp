#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long b;
    int h[20005];
    cin>>n>>b;
    for(int i=0;i<n;i++)
        cin>>h[i];
    sort(h,h+n);
    long long sum=0;
    int ans=0;
    int idx=n-1;
    while(1)
    {
        sum+=h[idx];
        ans++;
        if(sum>=b)
            break;
        idx--;
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,n;
    int close=0,far;
    int man[5005];
    cin>>l;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>man[i];
    if(n==0)
    {
        cout<<"0 0";
        return 0;
    }
    sort(man,man+n);
    far=max(l+1-man[0],man[n-1]);
    for(int i=0;i<n;i++)
    {
        if(man[i]<=l/2)
            close=max(close,man[i]);
        else
            close=max(close,l+1-man[i]);
    }
    cout<<close<<" "<<far;
    return 0;
}

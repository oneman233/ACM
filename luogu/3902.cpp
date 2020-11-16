#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100005];
    int s[100005],idx=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    s[idx]=a[0];
    idx++;
    for(int i=1;i<n;++i){
        if(a[i]>s[idx-1]){
            s[idx]=a[i];
            idx++;
        }
        else{
            int pos=upper_bound(s,s+idx,a[i])-s;
            s[pos]=a[i];
        }
    }
    cout<<n-idx;
    return 0;
}

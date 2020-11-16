#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,a[100005];
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int temp=0;
    for(int i=0;i<n;++i){
        temp+=a[i];
        a[i]=temp;
    }
    for(int i=0;i<n;++i)
        a[i]%=k;
    /*
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    */
    ///实际上要考虑的是把这些余数相同的搞到一块儿才可以构造出“K倍区间”
    map<int,int> m;
    int ans=0;
    for(int i=0;i<n;++i){
        if(a[i]==0)
            ++ans;
        ans+=m[a[i]];
        m[a[i]]++;
    }
    cout<<ans;
    return 0;
}

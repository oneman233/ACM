#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll a[500005];

bool chk(ll as)
{
    ll ct=0,sm=0;
    for(int i=1;i<=n;++i){
        if(sm+a[i]<=as) sm+=a[i];
        else sm=a[i],ct++;
    }
    return ct>=m;
}

int main()
{
    cin>>n>>m;
    ll sm=0,bg=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sm+=a[i];
        bg=max(bg,a[i]);
    }
    ll l=bg,r=sm;
    while(l<=r){
        ll m=(l+r)/2;
        if(chk(m)) l=m+1;
        else r=m-1;
    }
    cout<<l;
    return 0;
}
/*
5 3
4 2 4 5 1
*/

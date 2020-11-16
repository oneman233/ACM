#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int m,k;
ll p[505];

bool chk(ll as)
{
    ll ct=0,sm=0;
    for(int i=1;i<=m;++i){
        sm+=p[i];
        if(sm>as){
            sm=p[i];
            ct++;
        }
    }
    return ct>=k;
}

int main()
{
    cin>>m>>k;
    ll l=0,r=0;
    for(int i=1;i<=m;++i){
        cin>>p[i];
        l=max(l,p[i]);
        r+=p[i];
    }
    while(l<=r){
        ll m=(l+r)/2;
        if(chk(m)) l=m+1;
        else r=m-1;
    }
    int fg=1;
    ll sm=0;
    for(int i=1;i<=m;++i){
        sm+=p[i];
        if(sm>l){
            sm=p[i];
            cout<<fg<<" "<<i-1<<endl;
            fg=i;
        }
    }

    return 0;
}

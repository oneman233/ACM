#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[1005],sum;
ll ans[5];
bool can=false;

void dfs(ll i,ll idx)
{
    if(i>=n||idx>=3||can)
        return;
    if(ans[0]+ans[1]+ans[2]==sum)
    {
        can=true;
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
        return;
    }
    ans[idx]=a[i];
    dfs(i+1,idx+1);
    dfs(i+1,idx);
}

int main()
{
    cin>>n;
    ll tmp=0LL;
    for(int i=0;i<n;++i)
        cin>>a[i],tmp+=a[i];
    cin>>sum;
    if(tmp<sum){
        cout<<"NO"<<endl;
        return 0;
    }
    sort(a,a+n);
    dfs(0,0);
    if(!can)
        cout<<"NO";
    return 0;
}

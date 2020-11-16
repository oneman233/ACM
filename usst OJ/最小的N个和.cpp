#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=100000;

int main()
{
    int n;
    ll a[Max+5],b[Max+5];
    cin>>n;
    _for(i,0,n)
        cin>>a[i];
    _for(i,0,n)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    map<ll,ll> m;
    _for(i,0,101)
    {
        if(i>=n)
            break;
        _for(j,0,n)
        {
            m[a[i]+b[j]]++;
        }
    }
    map<ll,ll>::iterator it;
    int cnt=0;
    for(it=m.begin();it!=m.end();++it)
    {
        while(it->second!=0)
        {
            cout<<it->first;
            cnt++;
            it->second--;
            if(cnt!=n)
                cout<<" ";
            if(cnt==n)
                break;
        }
        if(cnt==n)
            break;
    }
    return 0;
}

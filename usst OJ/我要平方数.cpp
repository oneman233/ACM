#include <bits/stdc++.h>
#define ll long long
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;
const ll INF=0x3f3f3f3f;

ll tenpow(int a)
{
    ll ans=1;
    _for(i,0,a)
        ans*=10;
    return ans;
}

int main()
{
    set<ll> s;
    vector<int> v;
    for(ll i=1;i<=120000;i++)
    {
        s.insert(i*i);
    }
    long long ans=INF;
    string n;
    cin>>n;
    _for(i,1,(1<<n.length()))
    {
        int zero=0;
        v.clear();
        _for(j,0,n.length())
        {
            if(i&(1<<j))
            {
                v.push_back(n[j]-'0');
            }
            else
                zero++;
        }
        if(v[0]==0)
            continue;/*前导零*/
        ll temp=0;
        _for(j,0,v.size())
        {
            temp+=v[j]*tenpow(v.size()-1-j);
        }
        if(s.count(temp))
        {
            if(zero<ans)
                ans=zero;
        }
    }
    if(ans>=20)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}

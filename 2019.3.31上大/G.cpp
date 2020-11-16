#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;
const int Max=1000000;

ll n,m,s,k=10000;
///n个人，m个要求，s个数量
ll x[Max],y[Max],r[Max],ti[Max];

int main()
{
    sci(n);
    sci(m);
    sci(s);
    _for(i,0,m)
    {
        sci(x[i]);
        sci(y[i]);
        sci(r[i]);
    }
    while(k)
    {
        _rep(i,1,n)
            ti[i]=0;
        int ci=100;
        while(ci--)
        {
            _for(i,0,m)
                ti[y[i]]=max(ti[y[i]],ti[x[i]]+r[i]*k);
        }
        int cnt=0;
        _rep(i,1,n)
            cnt+=ti[i];
        if(cnt<=s)
        {
            _rep(i,1,n)
                cout<<ti[i]<<" ";
            break;
        }
        k--;
    }
    if(k==100000)
        cout<<-1;
    else if(k==0)
        cout<<0;
    else
        cout<<k;
    return 0;
}

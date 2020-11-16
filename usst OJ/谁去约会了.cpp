#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

set<ll> s;
ll read,a[Max];

int main()
{
    int n;
    scanf("%d",&n);
    _for(i,0,n)
    {
        scanf("%lld",&a[i]);
    }
    _for(i,0,n-1)
    {
        scanf("%lld",&read);
        s.insert(read);
    }
    for(int i=n-1;i>=0;--i)
    {
        if(!s.count(a[i]))
        {
            printf("%lld",a[i]);
            break;
        }
    }
    return 0;
}

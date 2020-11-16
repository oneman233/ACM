#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=500000;

ll n,sum=0;
int m,k;
ll a[Max+5];

int main()
{
    scanf("%lld %d %d",&n,&m,&k);
    _for(i,0,k)
        scanf("%lld",&a[i]);
    int temp=0;
    for(int i=k-1;i>=0;--i)
    {
        if(n>=a[i])
        {
            n-=a[i];
            sum+=a[i];
            temp++;
            if(temp==m)
                break;
        }
    }
    if(temp==sum)
        cout<<sum;
    else
        cout<<-1;
    return 0;
}

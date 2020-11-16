#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

int main()
{
    ll n;
    scanf("%lld",&n);
    if(n==1)
    {
        printf("1/1");
        return 0;
    }
    if(n==3)
    {
        printf("2/1");
        return 0;
    }
    ll he=1;
    while(1)
    {
        if(he*(he+1)/2==n)
        {
            printf("1/%lld",he);
            return 0;
        }
        if(he*(he+1)/2>n)
            break;
        he++;
    }
    ll cnt=n-he*(he-1)/2-1;
    ll a,b;
    bool ou;
    if((he+1)%2==0)
    {
        ou=true;
        a=he;
        b=1;
    }
    else
    {
        ou=false;
        a=1;
        b=he;
    }
    while(cnt--)
    {
        if(ou)
        {
            a--;
            b++;
        }
        else
        {
            a++;
            b--;
        }
    }
    printf("%lld/%lld",a,b);
    return 0;
}

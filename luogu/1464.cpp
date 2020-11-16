#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

ll rem[30][30][30];

ll f(ll a, ll b, ll c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(rem[a][b][c]!=0)
        return rem[a][b][c];
    else if(a>20||b>20||c>20)
        rem[a][b][c]=f(20,20,20);
    else if(a<b&&b<c)
        rem[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
    else
        rem[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
    return rem[a][b][c];
}

int main()
{
    ll a,b,c;
    while(scanf("%lld %lld %lld",&a,&b,&c))
    {
        memset(rem,0,sizeof(rem));
        if(a==-1&&b==-1&&c==-1)
            break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a>20)
            a=21;
        if(b>20)
            b=21;
        if(c>20)
            c=21;
        printf("%lld\n",f(a,b,c));
    }
    return 0;
}

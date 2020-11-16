#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;
const int Max=500000;

int n,cgcd,cnt=0;
int a[110],dp[Max];

int gcd(int x,int y)
{
    if(x<y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    while(y)
    {
        int temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}

int main()
{
    sci(n);
    _for(i,0,n)
        sci(a[i]);
    cgcd=a[0];
    _for(i,1,n)
        cgcd=gcd(cgcd,a[i]);
    if(cgcd!=1)
        cout<<"INF";
    else
    {

    }
    return 0;
}

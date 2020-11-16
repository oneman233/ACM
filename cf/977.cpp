#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    sci(n);
    sci(k);
    while(k--)
    {
        if(n%10==0)
            n/=10;
        else
            n--;
    }
    pri(n);
    return 0;
}

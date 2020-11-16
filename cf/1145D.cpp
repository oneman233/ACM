#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int main()
{
    int n,a[100];
    sci(n);
    _for(i,0,n)
        sci(a[i]);
    srand(time(NULL));
    pri(a[rand()%n]);
    return 0;
}

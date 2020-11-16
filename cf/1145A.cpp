#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int n,a[105],b[105];

int f(int l,int r)
{
    if(r<l)
        return 0;
    if(r==l)
        return 1;
    bool isord=true;
    _for(i,l+1,r)
    {
        if(a[i]<a[i-1])
        {
            isord=false;
            break;
        }
    }
    if(isord)
        return r-l;
    else
        return max(f(l,(l+r)/2),f((l+r)/2,r));
}

int main()
{
    sci(n);
    _for(i,0,n)
    {
        sci(a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    bool isord=true;
    _for(i,0,n)
    {
        if(a[i]!=b[i])
        {
            isord=false;
            break;
        }
    }
    if(isord)
        pri(n);
    else
    {
        pri(max(f(0,n/2),f(n/2,n)));
    }
    return 0;
}

#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    int s,e;
    long long a[85];
    memset(a,0,sizeof(a));
    cin>>s>>e;
    a[s+1]=1;
    a[s+2]=2;
    _for(i,s+3,e+1)
        a[i]=a[i-1]+a[i-2];
    cout<<a[e];
    return 0;
}

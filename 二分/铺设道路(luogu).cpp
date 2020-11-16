#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

ll ans=0;
int n,d[Max];

void fil(int l,int r)
{
    if(l>r)
        return;
    int sml=Max;
    _rep(i,l,r)
        sml=sml<d[i]?sml:d[i];
    _rep(i,l,r)
        d[i]-=sml;
    int zero;
    _rep(i,l,r)
        if(d[i]==0)
            zero=i;
    ans+=sml;
    /*
    _for(i,l,r)
        cout<<d[i]<<" ";
    cout<<endl;
    */
    fil(l,zero-1);
    fil(zero+1,r);
}

int main()
{
    scanf("%d",&n);
    _for(i,0,n)
        scanf("%d",&d[i]);
    fil(0,n-1);
    printf("%lld",ans);
    return 0;
}

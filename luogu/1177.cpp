#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

int m;
ll n[Max+100];

void qsor(int l,int r)
{
    if(l>r)
        return;
    int i=l,j=r;
    ll flag=n[l];///
    while(i<j)
    {
        while(j>i&&n[j]>=flag)
            j--;
        n[i]=n[j];
        while(i<j&&n[i]<=flag)
            i++;
        n[j]=n[i];
    }
    n[i]=flag;
    qsor(l,i-1);
    qsor(i+1,r);
}

int main()
{
    scanf("%d",&m);
    _for(i,0,m)
        scanf("%lld",&n[i]);
    qsor(0,m-1);
    _for(i,0,m)
    {
        printf("%lld",n[i]);
        if(i!=m-1)
            printf(" ");
    }
    return 0;
}

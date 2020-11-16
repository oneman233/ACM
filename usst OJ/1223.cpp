#include <bits/stdc++.h>
using namespace std;

const int maxn=100000;

int n;
struct man
{
    double t;
    int p;
}m[maxn+5];

bool cmp(man a,man b)
{
    return a.t<b.t;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf",&m[i].t),m[i].p=i;
    sort(m+1,m+1+n,cmp);
    double sum=0.0;
    for(int i=1;i<=n;++i)
    {
        printf("%d",m[i].p);
        if(i!=n)
            printf(" ");
    }
    for(int i=1;i<=n-1;++i)
        sum+=m[i].t*(n-i);
    printf("\n%.2lf",sum/n);
    return 0;
}

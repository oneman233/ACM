#include <bits/stdc++.h>
using namespace std;

int n,k;
int e[11];
struct man
{
    int w,p;
}m[20005];

bool cmp(man a,man b)
{
    return a.w>b.w;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=10;++i)
        scanf("%d",&e[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&m[i].w);
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=n;++i)
    {
        m[i].p=i;
        m[i].p=(m[i].p-1)%10+1;
    }
    for(int i=1;i<=n;++i)
        m[i].w+=e[m[i].p];

    return 0;
}

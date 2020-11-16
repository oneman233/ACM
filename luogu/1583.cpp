#include <bits/stdc++.h>
using namespace std;

int n,k,e[11];
struct man
{
    int w,d,i;
}m[20005];

bool cmp(man a,man b)
{
    if(a.w!=b.w)
        return a.w>b.w;
    else
        return a.i<b.i;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=10;++i)
        cin>>e[i];
    for(int i=1;i<=n;++i){
        cin>>m[i].w;
        m[i].i=i;
    }
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=n;++i)
        m[i].d=i;
    for(int i=1;i<=n;++i)
        m[i].w+=e[(m[i].d-1)%10+1];
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=k;++i)
    {
        cout<<m[i].i;
        if(i!=k)
            cout<<" ";
    }
    return 0;
}

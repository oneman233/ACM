#include <bits/stdc++.h>
using namespace std;

int n,m;
struct man
{
    int k;
    int s;
}a[10000];

bool cmp(man a,man b)
{
    if(a.s!=b.s)
        return a.s>b.s;
    else
        return a.k<b.k;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i].k>>a[i].s;
    sort(a+1,a+1+n,cmp);
    m=m*3/2;
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i].s>=a[m].s)
            cnt++;
        else
            break;
    }
    cout<<a[m].s<<" "<<cnt<<endl;
    for(int i=1;i<=cnt;++i)
        cout<<a[i].k<<" "<<a[i].s<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m;
struct cow
{
    int p;
    int a;
}c[5010];

bool cmp(cow a,cow b)
{
    return a.p<b.p;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
        cin>>c[i].p>>c[i].a;
    sort(c,c+m,cmp);
    int tmp=0;
    long long ans=0;
    for(int i=0;i<m;++i)
    {
        if(tmp+c[i].a<n)
        {
            tmp+=c[i].a;
            ans+=c[i].p*c[i].a;
        }
        else
        {
            ans+=c[i].p*(n-tmp);
            break;
        }
    }
    cout<<ans;
    return 0;
}

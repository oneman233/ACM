#include <bits/stdc++.h>
using namespace std;

struct jashdjkakshdkjawhddljash
{
    int s,e;
}a[1000010];

bool cmp(jashdjkakshdkjawhddljash x,jashdjkakshdkjawhddljash y)
{
    if(x.e!=y.e)
        return x.e<y.e;
    else
        return x.s>y.s;
}

int main()
{
    int n,ans=1;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].s>>a[i].e;
    }
    sort(a,a+n,cmp);
    int tmp=a[0].e;
    for(int i=1;i<n;++i)
    {
        if(a[i].s>=tmp)
        {
            tmp=a[i].e;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int k,h,a[1050];
int ans=0;

bool check(int x)
{
    int tmp[1050];
    for(int i=0;i<=x;++i)
        tmp[i]=a[i];
    sort(tmp,tmp+x+1);
    int high=0;
    for(int i=x;i>=0;i-=2)
    {
        high+=tmp[i];
        if(high>h)
            return false;
    }
    ans=max(ans,x+1);
    return true;
}

int main()
{
    cin>>k>>h;
    for(int i=0;i<k;++i)
        cin>>a[i];
    for(int i=k-1;i>=0;--i)
        if(check(i))
            break;
    cout<<ans;
    return 0;
}

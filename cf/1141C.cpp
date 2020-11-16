#include <bits/stdc++.h>
using namespace std;
const int Max=200000;

long long n;
long long q[Max+10],sum[Max+10];

int main()
{
    sum[0]=0;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>q[i];
        if(q[i]==0)///有两个数差为零，即相同
        {
            cout<<-1;
            return 0;
        }
        sum[i]+=q[i]+sum[i-1];
    }
    bool can=true;
    set<int> s;
    long long big=-Max-10,sml=Max+10;
    for(int i=1;i<n;++i)
    {
        s.insert(sum[i]);
        big=max(big,sum[i]);
        sml=min(sml,sum[i]);
    }
    if(sml<-(n-1)||sml>1||big>n-1||s.count(0)!=0)///区间不重合或者有0
    {
        cout<<-1;
        return 0;
    }
    for(int i=sml;i<=big;++i)
    {
        if(s.count(i)==0&&i!=0)
        {
            can=false;///判断有没有缺少数字以至于无法构成排列
            break;
        }
    }
    if(s.size()!=n-1)///差值数量不对
    {
        cout<<-1;
        return 0;
    }
    if(can)
    {
        long long ans=min(n,n-big);///
        cout<<ans;
        for(int i=1;i<n;++i)
            cout<<" "<<ans+sum[i];
    }
    else
        cout<<-1;
    return 0;
}

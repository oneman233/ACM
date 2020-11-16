#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

int n;
struct bigint
{
    vector<int> v;
    void operator = (bigint num)
    {
        v=num.v;
    }
    bigint operator + (bigint num)
    {
        bigint ans;
        vector<int> tmp;
        while(v.size()<num.v.size())
            v.insert(v.begin(),0);
        while(num.v.size()<v.size())
            num.v.insert(num.v.begin(),0);
        int len=v.size();
        for(int i=0;i<len;++i)
            tmp.pb(v[i]+num.v[i]);
        for(int i=len-1;i>=1;--i)
        {
            if(tmp[i]>=10)
            {
                tmp[i]%=10;
                tmp[i-1]++;
            }
        }
        if(tmp[0]>=10)
        {
            tmp[0]%=10;
            tmp.insert(tmp.begin(),1);
        }
        ans.v=tmp;
        return ans;
    }
    void put()
    {
        for(int i=0;i<v.size();++i)
            cout<<v[i];
    }
}a[5050];

int main()
{
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    a[1].v.pb(1);
    a[2].v.pb(2);
    for(int i=3;i<=n;++i)
        a[i]=a[i-1]+a[i-2];
    a[n].put();
    return 0;
}

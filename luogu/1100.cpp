#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num;
    string in,s="";
    cin>>num;
    for(int i=31;i>=0;--i)
    {
        if(num&(1<<i))
            in.append(1,'1');
        else
            in.append(1,'0');
    }
    /*
    while(in.length()<32)
        in.insert(in.begin(),'0');
    */
    for(int i=16;i<=31;++i)
        s.append(1,in[i]);
    for(int i=0;i<=15;++i)
        s.append(1,in[i]);
    long long tmp=1,ans=0;
    for(int i=31;i>=0;--i)
    {
        if(s[i]=='1')
            ans+=tmp;
        tmp*=2;
    }
    cout<<ans;
    return 0;
}

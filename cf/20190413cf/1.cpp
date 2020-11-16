#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool can=true;
    int n,t,s[110],d;
    cin>>n>>t;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i]>>d;
        if(s[i]<t)
        {
            while(s[i]<t)
                s[i]+=d;
        }
        if(s[i]==t)
        {
            cout<<i;
            can=false;
            break;
        }
    }
    if(can)
    {
        int ans,sml=10000000;
        for(int i=1;i<=n;++i)
        {
            if(s[i]<sml)
            {
                sml=s[i];
                ans=i;
            }
        }
        cout<<ans;
    }
    return 0;
}

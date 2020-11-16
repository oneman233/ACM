#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
string s;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        ll ans=0;
        ll tmp[11];
        for(int i=2;i<=10;++i)
            tmp[i]=1;
        for(int i=s.length()-1;i>=0;--i)
        {
            if(s[i]=='1')
            {
                for(int i=2;i<=10;++i)
                    ans+=tmp[i];
            }
            for(int i=2;i<=10;++i)
                tmp[i]*=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

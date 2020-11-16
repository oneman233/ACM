#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
using namespace std;
typedef long long ll;

signed main()
{
    int ans=0;
    string s,tmp;
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
        for(int j=i;j<s.length();++j)
        {
            int len=j-i+1;
            string tmp=s.substr(i,len);
            bool can=false;
            for(int k=0;k+len-1<s.length();++k)
            {
                if(k==i)
                    continue;
                if(s.substr(k,len)==tmp)
                {
                    can=true;
                    break;
                }
            }
            if(can)
                ans=tmp.length()>ans?tmp.length():ans;
        }
    }
    prl(ans);
    return 0;
}

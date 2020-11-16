#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;

string s;
int dp[100005];

signed main()
{
    cin>>s;
    int len=s.length();
    dp[0]=1;
    if(s[1]!='0')
        dp[1]=1;
    if(s[0]=='1')
        dp[1]++;
    if(s[0]=='2'&&s[1]>='0'&&s[1]<='6')
        dp[1]++;
    for(int i=2;i<len;++i){
        if(s[i]!='0'){
            dp[i]=dp[i-1];
            dp[i]%=mod;
        }
        if(s[i-1]=='1'){
            dp[i]+=dp[i-2];
            dp[i]%=mod;
        }
        if(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6'){
            dp[i]+=dp[i-2];
            dp[i]%=mod;
        }
    }
    /*
    for(int i=0;i<len;++i)
        cout<<dp[i]<<' ';
    */
    printf("%lld",dp[len-1]%mod);
    return 0;
}

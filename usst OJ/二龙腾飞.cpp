#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int m,n;
int v[55],num[55];
int dp[20005],chk=0;

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;++i)
        cin>>v[i]>>num[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;++i){
        int cnt=1;
        while(cnt<=num[i]){
            for(int j=m;j>=cnt*v[i];j--)
                dp[j]=min(dp[j],dp[j-cnt*v[i]]+cnt);
            num[i]-=cnt;
            cnt*=2;
        }
        if(num[i]!=0)
            for(int j=m;j>=num[i]*v[i];j--)
                dp[j]=min(dp[j],dp[j-num[i]*v[i]]+num[i]);
    }
    if(dp[m]<inf)
        cout<<dp[m];
    else
        cout<<"unhappy";
    return 0;
}
/*
100 2
10 5
5 1

100 3
50 1
10 50
5 100
*/

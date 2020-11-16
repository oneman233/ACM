#include <bits/stdc++.h>
using namespace std;

char a[1005],b[1005];
int dp[1005][1005];

int main()
{
    a[0]='A';
    b[0]='B';
    scanf("%s",a+1);
    int n=strlen(a)-1;
    for(int i=1;i<=n;++i)
        b[i]=a[n-i+1];
    ///printf("%s %s",a,b);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d",n-dp[n][n]);
    return 0;
}

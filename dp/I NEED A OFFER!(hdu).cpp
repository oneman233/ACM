#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n == 0 && m == 0)
            break;
        int a[10005];
        double b[10005];
        _for(i,0,m)
            cin>>a[i]>>b[i];
        double dp[10005];
        _for(i,0,n+1)
            dp[i] = 0.0;
        _for(i,0,m)
        {
            for(int j=n;j>=0;--j)
            {
                if(j >= a[i])
                    dp[j] = max(dp[j], 1.0-(1.0-dp[j-a[i]])*(1.0-b[i]));
            }
        }
        double ans=0.0;
        _for(i,0,n+1)
            ans = max(ans, dp[i]);
        printf("%.1lf%%\n",ans*100.0);
    }
}

///一些总结：
///遍历顺序非常重要，应该先检查每一种货物，再由大到小检查容量
///否则会出现一个物品买多次的情况
///但是换个角度想，如果一个物品可以买多次，那么就应该交换顺序！！！
///一般情况下可以不用给dp做传递，最后遍历一遍找最大值也是ok的

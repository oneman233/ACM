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

///һЩ�ܽ᣺
///����˳��ǳ���Ҫ��Ӧ���ȼ��ÿһ�ֻ�����ɴ�С�������
///��������һ����Ʒ���ε����
///���ǻ����Ƕ��룬���һ����Ʒ�������Σ���ô��Ӧ�ý���˳�򣡣���
///һ������¿��Բ��ø�dp�����ݣ�������һ�������ֵҲ��ok��

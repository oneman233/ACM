#include <bits/stdc++.h>
#define int long long
using namespace std;

int k,n;
int num[105];
int s[100005],r[100005];
///s是结果集合
///r是对应位置质数需要乘以哪个丑数

signed main()
{
    cin>>k>>n;
    for(int i=0;i<k;++i)
        cin>>num[i];
    s[0]=1;
    for(int i=1;i<=n;++i){
        int sml=LONG_LONG_MAX;
        for(int j=0;j<k;++j){
            while(num[j]*s[r[j]]<=s[i-1])
                r[j]++;
            ///对每一个质数都要更新其r
            ///实际上这样也可以确保找到p1*p1的情况
            sml=min(sml,num[j]*s[r[j]]);
        }
        s[i]=sml;
    }
    cout<<s[n];
    return 0;
}

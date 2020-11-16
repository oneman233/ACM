#include <bits/stdc++.h>
using namespace std;

const int mod=19;///必须要求对一个质数取余

pow(int x,int y)
{
    int ans=1;
    while(y--)
    {
        ans*=x;
        ans%=mod;
    }
    return ans;
}

int main()
{
    int x,y;
    cin>>x>>y;
    ///求的是x^y%mod的值
    cout<<pow(x,y)%mod<<endl;
    y%=(mod-1);
    cout<<pow(x,y)%mod<<endl;
    ///在3^89及2^100情况下，答案一模一样
    return 0;
}

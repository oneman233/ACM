#include <bits/stdc++.h>
using namespace std;

const int mod=19;///����Ҫ���һ������ȡ��

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
    ///�����x^y%mod��ֵ
    cout<<pow(x,y)%mod<<endl;
    y%=(mod-1);
    cout<<pow(x,y)%mod<<endl;
    ///��3^89��2^100����£���һģһ��
    return 0;
}

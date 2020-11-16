#include <bits/stdc++.h>
using namespace std;

long long sum(long long x)///求各位数字的乘积
{
    long long ans=1;
    while(x)
    {
        ans*=x%10;
        x/=10;
    }
    return ans;
}

long long pow9(int x)///返回9^x
{
    long long ans=1;
    while(x--)
        ans*=9;
    return ans;
}

long long pow10(int x)///返回10^x
{
    long long ans=1;
    while(x--)
        ans*=10;
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    if(n/10==0)///一位数
        cout<<n;
    else
    {
        long long ans=sum(n);
        ///以下是首位是n的首位的最大值
        vector<int> v;
        long long tn=n;
        while(tn)
        {
            v.insert(v.begin(),tn%10);
            tn/=10;
        }
        long long temp=v[0];
        for(int i=1;i<=v.size()-2;++i)
        {
            ans=max(ans,temp*(v[i]-1)*pow9(v.size()-i-1));
            temp*=v[i];
        }
        ///以下是首位非n的首位的最大值
        string s;
        stringstream ss;
        ss<<n;
        ss>>s;
        if(s[0]=='1')
            ans=max(ans,pow9(s.length()-1));
        else
            ans=max(ans,(s[0]-'0'-1)*pow9(s.length()-1));
        cout<<ans<<endl;
    }
    return 0;
}

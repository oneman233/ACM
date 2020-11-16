#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,n;
    cin>>l>>n;
    string ans="";
    long long num=1;
    for(int i=0;i<l;i++)
        num*=26;
    n=num-n;//zheng shu di n ge
    for(int i=0;i<l;i++)
    {
        ans.append(1,n%26+'a');
        n/=26;
    }
    for(int i=ans.length()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}

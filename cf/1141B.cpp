#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char temp;
    string s="";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        s.append(1,temp);
    }
    s+=s;
    int ans=0,cnt=0;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]=='1')
        {
            cnt++;
            ans=max(ans,cnt);
        }
        else
            cnt=0;
    }
    cout<<ans;
    return 0;
}

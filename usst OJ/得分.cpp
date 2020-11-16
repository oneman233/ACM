#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans=0;
    int temp=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='O')
        {
            ans+=temp;
            temp++;
        }
        else
            temp=1;
    }
    cout<<ans;
    return 0;
}

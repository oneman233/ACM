#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans=(s[0]-'0')*1;
    for(int i=2;i<=4;i++)
        ans+=(s[i]-'0')*i;
    for(int i=6;i<=10;i++)
        ans+=(s[i]-'0')*(i-1);
    ans%=11;
    if(s[s.length()-1]=='X')
    {
        if(ans==10)
            cout<<"Right";
        else
        {
            for(int i=0;i<s.length()-1;i++)
                cout<<s[i];
            if(ans!=10)
                cout<<ans;
            else
                cout<<"X";
        }
    }
    else
    {
        if(ans==s[s.length()-1]-'0')
            cout<<"Right";
        else
        {
            for(int i=0;i<s.length()-1;i++)
                cout<<s[i];
            if(ans!=10)
                cout<<ans;
            else
                cout<<"X";
        }
    }
    return 0;
}

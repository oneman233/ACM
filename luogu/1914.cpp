#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    n%=26;
    string s;
    cin>>s;
    while(n--)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='z')
                s[i]='a';
            else
                s[i]++;
        }
    }
    cout<<s;
    return 0;
}

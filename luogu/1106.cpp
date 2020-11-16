#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int k;
    cin>>s;
    cin>>k;
    while(k--)
    {
        int i=0;
        for(;i<s.length()-1;++i)
            if(s[i]>s[i+1])
                break;
        s.erase(i,1);
    }
    while(s[0]=='0')
        s.erase(0,1);
    if(s.length()==0)
        cout<<0;
    else
        cout<<s;
    return 0;
}

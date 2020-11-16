#include <bits/stdc++.h>
using namespace std;

int n;
string s[100010],t;

bool ispre(string ts)
{
    if(t.length()>ts.length())
        return false;
    for(int i=0;i<t.length();++i)
        if(ts[i]!=t[i])
            return false;
    return true;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>s[i];
    cin>>t;
    sort(s,s+n);
    for(int i=0;i<n;++i)
        if(ispre(s[i]))
            cout<<s[i]<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;
int n=0;

int main()
{
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]=='0'||s[i]=='6'||s[i]=='9')
            n++;
        if(s[i]=='8')
            n+=2;
    }
    cout<<n;
    return 0;
}

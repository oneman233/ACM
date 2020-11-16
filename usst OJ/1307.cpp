#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    stack<char> s;
    cin>>n;
    bool isnega=false;
    if(n[0]=='-')
        isnega=true;
    for(int i=0;i<n.length();i++)
    {
        if(n[i]!='-')
            s.push(n[i]);
    }
    if(isnega)
        cout<<"-";
    while(!s.empty())
    {
        if(s.top()=='0')
            s.pop();
        else
            break;
    }
    if(s.empty())
        cout<<0;
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}

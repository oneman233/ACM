#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(int e)
{
    stack<char> tmp;
    tmp.push(s[0]);
    for(int i=1;i<=e;++i)
    {
        if(tmp.empty())
        {
            tmp.push(s[i]);
            continue;
        }
        if(s[i]==')'&&tmp.top()=='(')
            tmp.pop();
        else
            tmp.push(s[i]);
    }
    if(tmp.size()==0)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;
    cin>>s;
    return 0;
}

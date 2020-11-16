#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool can=true;
    string s;
    cin>>s;
    stack<char> c;
    for(int i=0;i<s.length();++i){
        if(s[i]=='(')
            c.push(s[i]);
        else if(s[i]==')'){
            if(c.empty()){
                can=false;
                break;
            }
            else
                c.pop();
        }
    }
    if(!c.empty())
        can=false;
    if(can)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

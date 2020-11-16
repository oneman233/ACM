#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ct=s.length();
    while(ct--){
        for(int i=0;i<s.length()-1;++i){
            if(s[i]=='o'&&s[i+1]=='o'){
                s[i]='@';
                s[i+1]='O';
            }
            else if(s[i]=='O'&&s[i+1]=='O'){
                s[i]='@';
                s[i+1]='@';
            }
        }
        for(int i=0;i<s.length();++i)
            if(s[i]=='@')
                s.erase(i,1);
        if(s.length()==0)
            break;
    }
    if(s.length())
        cout<<s;
    else
        cout<<0;
    return 0;
}

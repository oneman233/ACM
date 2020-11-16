#include <bits/stdc++.h>
using namespace std;

string s;
map<char,int> m;

int main()
{
    cin>>s;
    for(int i=0;i<s.length();++i){
        m[tolower(s[i])]++;
    }
    while(m['s']!=0||m['i']!=0||m['w']!=0){
        if(m['s']!=0){
            cout<<'S';
            m['s']--;
        }
        if(m['i']!=0){
            cout<<'I';
            m['i']--;
        }
        if(m['w']!=0){
            cout<<'W';
            m['w']--;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool can=true;
string encode,decode,s,out="";
map<char,char> m;

int main()
{
    cin>>encode>>decode>>s;
    for(char i='A';i<='Z';++i)
        m[i]='@';
    for(int i=0;i<encode.length();++i){
        if(m[encode[i]]=='@')
            m[encode[i]]=decode[i];
        else{
            if(decode[i]!=m[encode[i]]){
                can=false;
                break;
            }
        }
    }
    ///不同字母对应不同密文
    if(can){
        for(char i='A';i<='Z';++i){
            int ct=0;
            for(char j='A';j<='Z';++j){
                if(m[j]==i)
                    ct++;
            }
            if(ct!=1){
                can=false;
                break;
            }
        }
    }
    if(can){
        for(int i=0;i<s.length();++i)
            out.append(1,m[s[i]]);
    }
    if(can)
        cout<<out;
    else
        cout<<"Failed";
    return 0;
}

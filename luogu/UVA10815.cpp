#include <bits/stdc++.h>
using namespace std;

string tmp;
set<string> s;

int main()
{
    while(cin>>tmp){
        string newtmp="";
        for(int i=0;i<tmp.length();++i){
            if(isalpha(tmp[i]))
                newtmp.append(1,tolower(tmp[i]));
        }
        s.insert(newtmp);
    }
    for(auto i:s)
        cout<<i<<endl;
    return 0;
}

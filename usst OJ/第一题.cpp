#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin>>s;
    cout<<s.length()<<endl;
    for(int i=0;i<s.length();++i){
        cout<<s[i];
        if(i!=s.length()-1)
            cout<<" ";
    }
    return 0;
}

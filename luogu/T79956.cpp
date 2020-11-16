#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        int j=0;
        string ss="2019";
        bool can=true;
        for(int i=0;i<s.length();++i){
            if(s[i]!=s[j]){
                can=false;
                break;
            }
            j++;
            if(j>=4)
                j=0;
        }
        if(can)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

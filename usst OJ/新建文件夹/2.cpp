#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;
    getchar();
    while(t--){
        getline(cin,s);
        ///cout<<s<<endl;
        vector<string> v;
        stringstream ss;
        for(int i=0;i<s.length();++i){
            if(isalpha(s[i])){
                s[i]=tolower(s[i]);
            }
        }
        ss<<s;
        string tp;
        while(ss>>tp)
            v.push_back(tp);
        /*
        for(auto i:v)
            cout<<i<<endl;
        */
        for(int i=0;i<v.size();++i)
            v[i][0]=toupper(v[i][0]);
        if(v.size()==1){
            cout<<v[0]<<endl;
        }
        else if(v.size()==2){
            cout<<v[0][0]<<". "<<v[1]<<endl;
        }
        else if(v.size()==3){
            cout<<v[0][0]<<". "<<v[1][0]<<". "<<v[2]<<endl;
        }
    }
    return 0;
}

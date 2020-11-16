#include <bits/stdc++.h>
using namespace std;

int n;
set<string> s;
map<string,int> m;
string tp;

string tos(int x)
{
    string ss="";
    while(x){
        ss.insert(ss.begin(),x%10+'0');
        x/=10;
    }
    return ss;
}

int main()
{
    cin>>n;
    for(int cs=0;cs<n;++cs){
        cin>>tp;
        if(!s.count(tp)){
            cout<<"OK"<<endl;
            m[tp]=1;
            s.insert(tp);
        }
        else{
            cout<<tp+tos(m[tp])<<endl;
            m[tp]++;
            s.insert(tp+tos(m[tp]));
        }
    }
    return 0;
}

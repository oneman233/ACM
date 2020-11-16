#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string,int> m;
set<string> se;

int main()
{
    cin>>n;
    while(n--){
        cin>>s;
        m[s]++;
        se.insert(s);
    }
    string ans;
    int big=-100;
    for(auto i=se.begin();i!=se.end();++i){
        if(m[*i]>big){
            ans=*i;
            big=m[*i];
        }
    }
    cout<<ans;
    return 0;
}

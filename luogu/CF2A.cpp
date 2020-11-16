#include <bits/stdc++.h>
using namespace std;
const int inf=-0x3f3f3f3f;

int n;
map<string,int> m;
struct rem
{
    string name;
    int s;
}r[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>r[i].name>>r[i].s;
        m[r[i].name]+=r[i].s;
    }
    int mx=inf;
    for(auto i=m.begin();i!=m.end();++i)
        if(i->second>mx)
            mx=i->second;
    set<string> as;
    for(auto i=m.begin();i!=m.end();++i)
        if(i->second==mx)
            as.insert(i->first);
    if(as.size()==1){
        cout<<*as.begin();
        return 0;
    }
    m.clear();
    for(int i=0;i<n;++i){
        m[r[i].name]+=r[i].s;
        if(m[r[i].name]>=mx&&as.count(r[i].name)){
            cout<<r[i].name;
            return 0;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int np,cnt,tmp;
unordered_map<string,int> s,e;
string name,n;
string na[15];

int main()
{
    cin>>np;
    for(int i=0;i<np;++i){
        cin>>na[i];
        s[na[i]]=0;
        e[na[i]]=0;
    }
    for(int i=0;i<np;++i){
        cin>>name>>tmp>>cnt;
        s[name]=tmp;
        if(cnt!=0)
            e[name]+=tmp%cnt;
        for(int i=0;i<cnt;++i){
            cin>>n;
            e[n]+=tmp/cnt;
        }
    }
    for(int i=0;i<np;++i){
        cout<<na[i]<<" "<<e[na[i]]-s[na[i]]<<endl;
    }
    return 0;
}

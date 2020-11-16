#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<char,int> a,b;

bool chk(int x)
{
    int flg=x;
    while(flg+x<n){
        if(s.substr(0,x)!=s.substr(flg,x))
            return false;
        flg+=x;
    }
    for(int i=0;i<x&&flg<n;i++,flg++)
        if(s[i]!=s[flg])
            return false;
    return true;
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<n;++i)
        a[s[i]]++;
    int start;
    for(int i=0;i<n;++i){
        b[s[i]]++;
        if(b.size()==a.size()){
            start=i;
            break;
        }
    }
    bool can=false;
    for(int i=start+1;i<=n;++i)
        if(chk(i)){
            cout<<i;
            break;
        }
    return 0;
}

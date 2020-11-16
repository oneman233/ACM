#include <bits/stdc++.h>
using namespace std;

int b;
string x,y;
map<int,char> ic;
map<char,int> ci;

string add()
{
    vector<int> v;
    string ans="";
    while(x.length()<y.length())
        x.insert(x.begin(),'0');
    while(y.length()<x.length())
        y.insert(y.begin(),'0');
    for(int i=0;i<x.length();++i)
        v.push_back(ci[x[i]]+ci[y[i]]);
    /*
    for(int i=0;i<v.size();++i)
        cout<<v[i];
    cout<<endl
    */
    for(int i=v.size()-1;i>=1;--i)
    {
        if(v[i]>=b)
        {
            v[i-1]+=v[i]/b;
            v[i]%=b;
        }
    }
    if(v[0]>=b)
    {
        v.insert(v.begin(),v[0]/b);
        v[1]%=b;
    }
    for(int i=0;i<v.size();++i)
        ans.append(1,ic[v[i]]);
    return ans;
}

int main()
{
    for(int i=0;i<=9;++i)
        ic[i]='0'+i;
    for(int i=10;i<=36;++i)
        ic[i]='A'+i-10;
    for(char i='0';i<='9';++i)
        ci[i]=i-'0';
    for(char i='A';i<='Z';++i)
        ci[i]=i-'A'+10;
    ///init;
    cin>>b;
    cin>>x>>y;
    cout<<add();
    return 0;
}

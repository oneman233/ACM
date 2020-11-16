#include <bits/stdc++.h>
using namespace std;

string a,b;
map<char,int> m;

string mi()
{
    string s="";
    while(a.length()<b.length())
        a.insert(a.begin(),'0');
    while(b.length()<a.length())
        b.insert(b.begin(),'0');
    vector<int> v;
    for(int i=0;i<a.length();++i)
        v.push_back(m[a[i]]-m[b[i]]);
    for(int i=v.size()-1;i>=1;--i)
    {
        while(v[i]<0)
        {
            v[i]+=10;
            v[i-1]-=1;
        }
    }
    if(v[0]<0)
    {
        s.append(1,'-');
        for(int i=0;i<v.size();++i)
            v[i]=-v[i];
        for(int i=v.size()-1;i>=1;--i)
        {
            while(v[i]<0)
            {
                v[i]+=10;
                v[i-1]-=1;
            }
        }
        int idx=0;
        while(v[idx]==0)
            idx++;
        while(idx<v.size())
        {
            s.append(1,v[idx]+'0');
            idx++;
        }
        return s;
    }
    else
    {
        int idx=0;
        while(v[idx]==0&&idx<v.size())
            idx++;
        if(idx==v.size())
            return "0";
        else
        {
            while(idx<v.size())
            {
                s.append(1,v[idx]+'0');
                idx++;
            }
            return s;
        }
    }
}

int main()
{
    for(char i='0';i<='9';++i)
        m[i]=i-'0';
    ///init;
    cin>>a>>b;
    cout<<mi();
    return 0;
}

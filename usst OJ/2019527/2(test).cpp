#include <bits/stdc++.h>
using namespace std;

string qianhou(string s)
{
    string tmp="";
    int n=s.length();
    if(s.length()%2==0){
        for(int i=n/2;i<s.length();++i)
            tmp.append(1,s[i]);
        for(int i=0;i<n/2;++i)
            tmp.append(1,s[i]);
    }
    else{
        for(int i=n/2+1;i<s.length();++i)
            tmp.append(1,s[i]);
        tmp.append(1,s[n/2]);
        for(int i=0;i<n/2;++i)
            tmp.append(1,s[i]);
    }
    return tmp;
}

string onetwo(string s)
{
    string tmp="";
    int n=s.length();
    if(s.length()%2==0){
        for(int i=1;i<s.length();i+=2){
            tmp.append(1,s[i]);
            tmp.append(1,s[i-1]);
        }
    }
    else{
        for(int i=1;i<s.length();i+=2){
            tmp.append(1,s[i]);
            tmp.append(1,s[i-1]);
        }
        tmp.append(1,s[s.length()-1]);
    }
    return tmp;
}

int main()
{
    int n;
    cin>>n;
    set<string> se;
    string s="";
    for(int i=0;i<n;++i)
        s.append(1,'0'+i);
    se.insert(s);
    int cnt=100000;
    while(cnt--){
        if(cnt&1)
            s=qianhou(s);
        else
            s=onetwo(s);
        se.insert(s);
    }
    cout<<se.size();
    return 0;
}

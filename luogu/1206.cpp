#include <bits/stdc++.h>
using namespace std;

int b;
vector<string> s,ans;
map<int,char> m;
///ans存放十进制数，s存放b进制数

bool check(string x)
{
    for(int i=0;i<x.length()/2;++i)
    {
        if(x[i]!=x[x.length()-1-i])
            return false;
    }
    return true;
}

void change(int x)
{
    int num=x;
    x*=x;
    string tmp="";
    while(x)
    {
        tmp.append(1,m[x%b]);
        x/=b;
    }
    if(check(tmp))
    {
        string a="";
        while(num)
        {
            a.insert(a.begin(),m[num%b]);
            num/=b;
        }
        ans.push_back(a);
        s.push_back(tmp);
    }
}

int main()
{
    for(int i=0;i<=9;++i)
        m[i]=i+'0';
    for(int i=10;i<=20;++i)
        m[i]=i-10+'A';
    ///init
    cin>>b;
    for(int i=1;i<=300;++i)
        change(i);
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<" "<<s[i]<<endl;
    return 0;
}

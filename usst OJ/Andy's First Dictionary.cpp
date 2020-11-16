#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> s;
    string a,b;
    while(cin>>a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(isalpha(a[i]))
                a[i]=tolower(a[i]);//消除大写
            else
                a[i]=' ';//空格在string流当中会被忽略
        }
        stringstream temp(a);
        while(temp>>b)//防止逗号
            s.insert(b);
    }
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<"\n";
    return 0;
}

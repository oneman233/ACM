#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
    if(a.length()>b.length())
        return true;
    else if(a.length()<b.length())
        return false;
    else
    {
        for(int i=0;i<a.length();++i)
        {
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        }
        return true;///算的是大于等于
    }
}

int main()
{
    int n;
    cin>>n;
    string s[30],ts[30];
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        ts[i]=s[i];
    }
    sort(ts,ts+n,cmp);
    for(int i=0;i<n;++i)
    {
        if(s[i]==ts[0])
        {
            cout<<i+1<<endl;
            cout<<s[i];
            break;
        }
    }
    return 0;
}

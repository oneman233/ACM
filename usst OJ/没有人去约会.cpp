#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

map<string,string> pre;
string s[105];
int n;
set<string> check;

string fin(string in)
{
    if(in==pre[in])
        return in;
    else
        return fin(pre[in]);
}

bool cmp(string a,string b)
{
    if(a==b)
        return true;
    int i,j,k;
    if(a.length()>b.length())
    {
        for(i=0;i<a.length();++i)
        {
            k=i;
            for(j=0;j<b.length();++j)
            {
                if(a[k]!=b[j])
                    break;
                ++k;
            }
            if(j==b.length())
                return true;
        }
        return false;
    }
    else
    {
        for(i=0;i<b.length();++i)
        {
            k=i;
            for(j=0;j<a.length();++j)
            {
                if(b[k]!=a[j])
                    break;
                ++k;
            }
            if(j==a.length())
                return true;
        }
        return false;
    }
}

int main()
{
    cin>>n;
    _for(i,0,n)
    {
        cin>>s[i];
        check.insert(s[i]);
    }
    if(check.size()==1)
    {
        cout<<"NO";
        return 0;
    }
    _for(i,0,n)
        pre[s[i]]=s[i];
    _for(i,0,n)
    {
        _for(j,i+1,n)
        {
            ///cout<<s[i]<<" "<<s[j]<<endl;
            if(cmp(s[i],s[j]))
                pre[fin(s[i])]=fin(s[j]);
        }
    }
    int cnt=0;
    _for(i,0,n)
    {
        ///cout<<pre[s[i]]<<endl;
        if(pre[s[i]]==s[i])
        {
            cnt++;
        }
    }
    if(cnt==1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}

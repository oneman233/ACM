#include <bits/stdc++.h>
using namespace std;

int ans=0;

bool check(string s)
{
    for(int i=0;i<=s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-1-i])
            return false;
    }
    return true;
}

string add(string s)
{
    string s1="";
    string out="";
    for(int i=s.length()-1;i>=0;i++)
        s1.append(1,s[i]);
    for(int i=0;i<s.length();i++)
        out.append(1,s[i]+s1[i]-'0');
    return out;
}

void huiwen(string s)
{
    if(check(s))
        return;
    else
    {
        ans++;
        if(ans>=30)
            return;
        huiwen(add(s));
    }
}

int main()
{
    int n;
    int temp=0;
    string m;
    string m1="";
    cin>>n;
    cin>>m;
    if(n!=16)
    {
        for(int i=0;i<m.length();i++)/**/
        {
            m1.append(1,((m[i]-'0'+temp)*n)/10);
            temp=((m[i]-'0')*n)%10;
        }
        huiwen(m1);
    }
    else
    {

    }
    if(ans>30)
        cout<<"impossible";
    else
        cout<<"STEP="<<ans;
    return 0;
}

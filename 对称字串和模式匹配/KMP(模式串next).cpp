#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int Max=100000;

string s,t;
int nex[Max];

void calnex()
{
    nex[1]=0,nex[1]=1;
    int i=1,j=0,len=t.length();
    while(i<=len)
    {
        if(j==0||t[i]==t[j])
        {
            i++;j++;
            if(t[i]!=t[j])
                nex[i]=j;
            else
                nex[i]=nex[j];
        }
        else
            j=nex[j];
    }
}

void kmp()
{
    int i=1,j=1,cnt=0;
    ///可以改变i的初始值控制从主串的哪个位置上开始匹配
    while(i<=s.length()&&j<=t.length())
    {
        if(j==0||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j=nex[j];
        if(j==t.length())
        {
            if(cnt!=0)
                cout<<" "<<i-t.length();
            else
                cout<<i-t.length();
            cnt++;
            j=1;
        }
    }
    if(cnt==0)
        cout<<-1;
    cout<<endl;
}

int main()
{
    while(cin>>s>>t)
    {
        s.insert(s.begin(),' ');
        t.insert(t.begin(),' ');
        ///让下标从1开始
        kmp();
    }
    return 0;
}

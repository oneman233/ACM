#include <bits/stdc++.h>
using namespace std;

string s;

void fenshu()
{
    int i=0;
    stack<char> qian,hou;
    for(;i<s.length();i++)
    {
        if(s[i]!='/')
            qian.push(s[i]);
        else
            break;
    }
    i++;
    for(;i<s.length();i++)
        hou.push(s[i]);
    while(!qian.empty())
    {
        if(qian.top()=='0')
            qian.pop();
        else
            break;
    }
    if(qian.empty())
        cout<<"0";
    while(!qian.empty())
    {
        cout<<qian.top();
        qian.pop();
    }
    cout<<"/";
    while(!hou.empty())
    {
        if(hou.top()=='0')
            hou.pop();
        else
            break;
    }
    while(!hou.empty())
    {
        cout<<hou.top();
        hou.pop();
    }
}
void xiaoshu()
{
    int i=0;
    stack<char> qian,hou;
    for(;i<s.length();i++)
    {
        if(s[i]!='.')
            qian.push(s[i]);
        else
            break;
    }
    i++;
    for(;i<s.length();i++)
        hou.push(s[i]);
    while(!qian.empty())
    {
        if(qian.top()=='0')
            qian.pop();
        else
            break;
    }
    if(qian.empty())
        cout<<"0";
    while(!qian.empty())
    {
        cout<<qian.top();
        qian.pop();
    }
    cout<<".";
    string out="";
    while(!hou.empty())
    {
        out.append(1,hou.top());
        hou.pop();
    }
    int j=out.length()-1;
    for(;j>=0;j--)
    {
        if(out[j]=='0');
        else
            break;
    }
    if(j==-1)
        cout<<"0";
    else
    {
        for(int k=0;k<=j;k++)
            cout<<out[k];
    }
}
void baifenshu()
{
    stack<char> ans;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='%')
            ans.push(s[i]);
    }
    while(!ans.empty())
    {
        if(ans.top()=='0')
            ans.pop();
        else
            break;
    }
    if(ans.empty())
        cout<<"0";
    /*去除末尾的0*/
    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }
    cout<<"%";
}
void common()
{
    stack<char> ans;
    for(int i=0;i<s.length();i++)
        ans.push(s[i]);
    while(!ans.empty())
    {
        if(ans.top()=='0')
            ans.pop();
        else
            break;
    }
    /*去除末尾的0*/
    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }
}

int main()
{
    cin>>s;
    if(s=="0")
    {
        cout<<"0";
        return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            xiaoshu();
            return 0;
        }
        if(s[i]=='%')
        {
            baifenshu();
            return 0;
        }
        if(s[i]=='/')
        {
            fenshu();
            return 0;
        }
    }
    common();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int i;
    string s,temp1="",temp2="",out="";//空的out字符串
    map<char,int> m;//找出现最多的字符
    stack<char> zhan;
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
    for(char i='a';i<='z';i++)
    {
        if(m[i]>ans)
            ans=m[i];
    }
    if(ans>s.length()/2)
    {
        cout<<"impossible";
        return 0;
    }
    /*for(int i=0;i<s.length();i++)
    {
        for(char j='a';j<='z';j++)
        {
            if(s[i]!=j&&m[j]!=0)
            {
                temp1.append(1,j);
                m[j]--;
                break;
            }
        }
    }
    for(char j='a';j<='z';j++)
    {
        while(m[j]!=0)
        {
            temp2.append(1,j);
            m[j]--;
        }
    }
    out=temp2+temp1;
    for(int i=0;i<out.length();i++)
    {
        while(out[i]==s[i])
        {
            zhan.push(out[i]);
            out.erase(i,1);
        }
        while(!zhan.empty())
        {
            out.append(1,zhan.top());
            zhan.pop();
        }
    }*/
    for(int i=s.length()-1;i>=0;i--)
        out.append(1,s[i]);
    for(int j=0;j<s.length();j++)
    {
        if(out[j]==s[j])
        {
            for(int i=0;i<s.length();i++)
            {
                if(i==j)
                    continue;
                if(out[j]!=s[i]&&s[j]!=out[i])
                {
                    char temp=out[i];
                    out[i]=out[j];
                    out[j]=temp;
                    break;
                }
            }
        }
    }
    cout<<out;
    return 0;
}

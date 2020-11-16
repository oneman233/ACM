/*
jin tian ken ding mei you bug
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string in)
{
    for(int i=0;i<in.length()/2;i++)
    {
        if(in[i]!=in[in.length()-i-1])
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        string ans="";
        for(char i='a';i<='z';i++)
        {
            while(m[i]>0)
            {
                ans.append(1,i);
                m[i]--;
            }
        }
        if(check(ans))
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}

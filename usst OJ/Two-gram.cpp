/*
jin tian ken ding mei you bug
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<string,int> m;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        string temp="";
        temp.append(1,s[i]);
        temp.append(1,s[i+1]);
        m[temp]++;
    }
    map<string,int>::iterator it;
    int ans=0;
    for(it=m.begin();it!=m.end();it++)
        ans=max(ans,it->second);
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second==ans)
        {
            cout<<it->first;
            break;
        }
    }
    return 0;
}

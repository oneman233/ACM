#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> ss;

int main()
{
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
        if(isdigit(s[i]))
        {
            int j=i;
            int num;
            string tmp="";
            while(s[j]!='.')
            {
                tmp.append(1,s[j]);
                ++j;
            }
            stringstream sss;
            sss<<tmp;
            sss>>num;
            ss.push(num);
            i=j;
        }
        else if(s[i]=='-')
        {
            int a=ss.top();
            ss.pop();
            int b=ss.top();
            ss.pop();
            ss.push(b-a);
        }
        else if(s[i]=='+')
        {
            int a=ss.top();
            ss.pop();
            int b=ss.top();
            ss.pop();
            ss.push(b+a);
        }
        else if(s[i]=='*')
        {
            int a=ss.top();
            ss.pop();
            int b=ss.top();
            ss.pop();
            ss.push(b*a);
        }
        else if(s[i]=='/')
        {
            int a=ss.top();
            ss.pop();
            int b=ss.top();
            ss.pop();
            ss.push(b/a);
        }
    }
    cout<<ss.top();
    return 0;
}

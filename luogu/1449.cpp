#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<int> n;
    for(int i=0;i<s.length();++i){
        if(s[i]=='-'){
            int b=n.top();
            n.pop();
            int a=n.top();
            n.pop();
            n.push(a-b);
        }
        else if(s[i]=='+'){
            int b=n.top();
            n.pop();
            int a=n.top();
            n.pop();
            n.push(a+b);
        }
        else if(s[i]=='*'){
            int b=n.top();
            n.pop();
            int a=n.top();
            n.pop();
            n.push(a*b);
        }
        else if(s[i]=='/'){
            int b=n.top();
            n.pop();
            int a=n.top();
            n.pop();
            n.push(a/b);
        }
        else if(isdigit(s[i])){
            int j=i;
            while(isdigit(s[j]))
                j++;
            stringstream ss;
            int tp;
            ss<<s.substr(i,j-i+1);
            ss>>tp;
            n.push(tp);
            i=j;
        }
    }
    cout<<n.top();
    return 0;
}

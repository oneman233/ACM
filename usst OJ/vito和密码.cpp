#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mis=0,pos;
    string a,b;
    cin>>a;
    cin>>b;
    vector<char> v;
    for(int i=0;i<b.length();i++)
    {
        if(b[i]=='-')
        {
            if(v.empty());
            else
                v.pop_back();
        }
        else if(b[i]=='+')
            break;
        else
            v.push_back(b[i]);
    }
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==v[i]);
        else
        {
            mis++;
            pos=i+1;
            if(mis>=2)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(mis==0)
        cout<<"YES";
    else
    {
        cout<<"NO"<<endl;
        cout<<pos;
    }
    return 0;
}

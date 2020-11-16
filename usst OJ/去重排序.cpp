#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<string> s;
    set<string>::iterator it;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}

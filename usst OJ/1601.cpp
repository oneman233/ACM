#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    vector<int> v;
    cin>>a>>b;
    while(a.length()<b.length())
        a.insert(a.begin(),'0');
    while(b.length()<a.length())
        b.insert(b.begin(),'0');
    //²¹Áã
    for(int i=0;i<a.length();i++)
        v.push_back(a[i]-'0'+b[i]-'0');
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]>=10)
        {
            v[i]%=10;
            if(i==0)
                v.insert(v.begin(),1);
            else
                v[i-1]++;
        }
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    return 0;
}
